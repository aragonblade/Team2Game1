// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/T2G1CharacterBase.h"

#include "AbilitySystemComponent.h"
#include "FT2G1_GameplayTags.h"
#include "Components/CapsuleComponent.h"
#include "GameplayAbility/AbilitySystemComponent/T2G1_AbilitySystemComponent.h"

class UGameplayEffect;

AT2G1CharacterBase::AT2G1CharacterBase()
{
 	PrimaryActorTick.bCanEverTick = false;
	
	
	GetMesh()->SetCollisionResponseToChannel(ECC_Camera, ECR_Ignore);
	GetMesh()->SetGenerateOverlapEvents(true);
	GetCapsuleComponent()->SetCollisionResponseToChannel(ECC_Camera, ECR_Ignore);
	
	
	WeaponMesh = CreateDefaultSubobject<USkeletalMeshComponent>("Weapon");
	WeaponMesh->SetupAttachment(GetMesh(), FName("WeaponHandSocket"));
	WeaponMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

UAbilitySystemComponent* AT2G1CharacterBase::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}
//init health and mana, other default attributes
void AT2G1CharacterBase::InitializeDefaultAttributes() const
{
	ApplyEffectToSelf(DefaultAttributes,1);
}

int32 AT2G1CharacterBase::GetPlayerLevel()
{
	return ICombatInterface::GetPlayerLevel();
}

FVector AT2G1CharacterBase::GetCombatSocketLocation_Implementation(const FGameplayTag& SocketTag)
{
	UE_LOG(LogTemp, Warning, TEXT("tag: %s"), *SocketTag.GetTagName().ToString());

	if (SocketTag.MatchesTagExact(FT2G1_GameplayTags::Get().CombatSocket_Weapon) && IsValid(WeaponMesh))
	{
		return WeaponMesh->GetSocketLocation(WeaponTipSocketName);
	}

	if (SocketTag.MatchesTagExact(FT2G1_GameplayTags::Get().CombatSocket_LeftHand))
	{
		return GetMesh()->GetSocketLocation(LeftHandSocketName);
	}

	if (SocketTag.MatchesTagExact(FT2G1_GameplayTags::Get().CombatSocket_RightHand))
	{
		return GetMesh()->GetSocketLocation(RightHandSocketName);
	}

	if (SocketTag.MatchesTagExact(FT2G1_GameplayTags::Get().CombatSocket_Tail))
	{
		return GetMesh()->GetSocketLocation(TailSocketName);
	}
	
	return FVector();
}

// Called when the game starts or when spawned
void AT2G1CharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AT2G1CharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AT2G1CharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AT2G1CharacterBase::InitAbilityActorInfo()
{
	
}

void AT2G1CharacterBase::ApplyEffectToSelf(TSubclassOf<UGameplayEffect> AttributesGameplayEffect, float Level) const
{
	check(IsValid(GetAbilitySystemComponent()));
	check(AttributesGameplayEffect);

	FGameplayEffectContextHandle ContextHandle = GetAbilitySystemComponent()->MakeEffectContext();
	ContextHandle.AddSourceObject(this);
	
	const FGameplayEffectSpecHandle SpecHandle = GetAbilitySystemComponent()->MakeOutgoingSpec(AttributesGameplayEffect, Level, ContextHandle);
	GetAbilitySystemComponent()->ApplyGameplayEffectSpecToTarget(*SpecHandle.Data.Get(), GetAbilitySystemComponent());

}

void AT2G1CharacterBase::AddCharacterAbilities()
{
	if (HasAuthority())
	{
		UT2G1_AbilitySystemComponent* T2G1ASC = CastChecked<UT2G1_AbilitySystemComponent>(AbilitySystemComponent);
		T2G1ASC->AddCharacterAbilities(StartupAbilities);
	}
}

