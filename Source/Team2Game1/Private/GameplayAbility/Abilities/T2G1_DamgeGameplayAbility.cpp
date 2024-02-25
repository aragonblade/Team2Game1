// Fill out your copyright notice in the Description page of Project Settings.


#include "GameplayAbility/Abilities/T2G1_DamgeGameplayAbility.h"

#include "AbilitySystemBlueprintLibrary.h"
#include "AbilitySystemComponent.h"
#include "Interaction/CombatInterface.h"

void UT2G1_DamgeGameplayAbility::CauseDamage(AActor* TargetActor)
{
	AActor* SourceActor = GetAbilitySystemComponentFromActorInfo()->GetAvatarActor();

	const FGameplayEffectSpecHandle DamageSpecHandle = MakeOutgoingGameplayEffectSpec(DamageEffectClass, 1);

	for	(auto Pair : DamageTypes )
	{
		const float ScaledDamage = Pair.Value.GetValueAtLevel(GetAbilityLevel());
		UE_LOG(LogTemp, Warning, TEXT("dmg: %f"), ScaledDamage);
		//float health = Cast<UAuraAttributeSet>(Cast<AAuraCharacter>(TargetActor)->GetAttributeSet())->GetHealthAttributeData();
		UAbilitySystemBlueprintLibrary::AssignTagSetByCallerMagnitude(DamageSpecHandle, Pair.Key, ScaledDamage);
	}
	GetAbilitySystemComponentFromActorInfo()->ApplyGameplayEffectSpecToTarget(*DamageSpecHandle.Data.Get(), UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(TargetActor));
	
}

FTaggedMontage UT2G1_DamgeGameplayAbility::GetRandomTaggedMontageFromArray(const TArray<FTaggedMontage>& TaggedMontages)
{
	if (TaggedMontages.Num() > 0)
	{
		const int32 Selection = FMath::RandRange(0, TaggedMontages.Num() - 1);
		return TaggedMontages[Selection];
	}

	return FTaggedMontage();
	
}
