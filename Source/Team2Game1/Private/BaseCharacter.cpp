// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseCharacter.h"

#include "AbilitySystemComponent.h"
#include "Components/CapsuleComponent.h"

class UGameplayEffect;

ABaseCharacter::ABaseCharacter()
{
 	PrimaryActorTick.bCanEverTick = false;
	
	
	GetMesh()->SetCollisionResponseToChannel(ECC_Camera, ECR_Ignore);
	GetMesh()->SetGenerateOverlapEvents(true);
	GetCapsuleComponent()->SetCollisionResponseToChannel(ECC_Camera, ECR_Ignore);
	
	
}

UAbilitySystemComponent* ABaseCharacter::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}
//init health and mana, other default attributes
void ABaseCharacter::InitializeDefaultAttributes() const
{
	ApplyEffectToSelf(DefaultAttributes,1);
}

// Called when the game starts or when spawned
void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ABaseCharacter::InitAbilityActorInfo()
{
	
}

void ABaseCharacter::ApplyEffectToSelf(TSubclassOf<UGameplayEffect> AttributesGameplayEffect, float Level) const
{
	check(IsValid(GetAbilitySystemComponent()));
	check(AttributesGameplayEffect);
	
	FGameplayEffectContextHandle ContextHandle = GetAbilitySystemComponent()->MakeEffectContext();
	ContextHandle.AddSourceObject(this);
	
	const FGameplayEffectSpecHandle SpecHandle = GetAbilitySystemComponent()->MakeOutgoingSpec(AttributesGameplayEffect, Level, ContextHandle);
	GetAbilitySystemComponent()->ApplyGameplayEffectSpecToTarget(*SpecHandle.Data.Get(), GetAbilitySystemComponent());

}

