// Fill out your copyright notice in the Description page of Project Settings.


#include "GameplayAbility/AbilitySystemComponent/T2G1_AbilitySystemComponent.h"

void UT2G1_AbilitySystemComponent::AbilityActorInfoSet()
{
	
}

void UT2G1_AbilitySystemComponent::AddCharacterAbilities(const TArray<TSubclassOf<UGameplayAbility>>& StartupAbilities)
{
	for (const TSubclassOf<UGameplayAbility> Ability : StartupAbilities)
	{
		FGameplayAbilitySpec AbilitySpec = FGameplayAbilitySpec(Ability, 1);
		//TODO: give ability to player
		GiveAbility(AbilitySpec);
	}
}

void UT2G1_AbilitySystemComponent::AbilityInputTagHeld(const FGameplayTag& InputTag)
{
	
}

void UT2G1_AbilitySystemComponent::AbilityInputTagReleased(const FGameplayTag& InputTag)
{
}

void UT2G1_AbilitySystemComponent::EffectApplied_Implementation(UAbilitySystemComponent* AbilitySystemComponent,
	const FGameplayEffectSpec& EffectSpec, FActiveGameplayEffectHandle ActiveGameplayEffectHandle)
{
	
}
