// Fill out your copyright notice in the Description page of Project Settings.


#include "GameplayAbility/AbilitySystemComponent/T2G1_AbilitySystemComponent.h"

#include "GameplayAbility/Abilities/T2G1_GameplayAbility.h"

void UT2G1_AbilitySystemComponent::AbilityActorInfoSet()
{
	OnGameplayEffectAppliedDelegateToSelf.AddUObject(this, &ThisClass::EffectApplied);
}

void UT2G1_AbilitySystemComponent::AddCharacterAbilities(const TArray<TSubclassOf<UGameplayAbility>>& StartupAbilities)
{
	for (const TSubclassOf<UGameplayAbility> Ability : StartupAbilities)
	{
		FGameplayAbilitySpec AbilitySpec = FGameplayAbilitySpec(Ability, 1);
		if (const UT2G1_GameplayAbility* GivenAbility = Cast<UT2G1_GameplayAbility>(AbilitySpec.Ability))
		{
			AbilitySpec.DynamicAbilityTags.AddTag(GivenAbility->StartupInputTag);
			UE_LOG(LogTemp, Warning, TEXT("Ability Tag Added: %s"), *GivenAbility->StartupInputTag.ToString());
			GiveAbility(AbilitySpec);
		}
	}
}

void UT2G1_AbilitySystemComponent::AbilityInputTagHeld(const FGameplayTag& InputTag)
{
	if (!InputTag.IsValid())
	{
		return;
	}
	UE_LOG(LogTemp, Warning, TEXT("AbilityInputTagHeld"));
	for	(auto& AbilitySpec : GetActivatableAbilities())
	{
		if (AbilitySpec.DynamicAbilityTags.HasTagExact(InputTag))
		{
			UE_LOG(LogTemp, Warning, TEXT("has InputTag"));
			AbilitySpecInputPressed(AbilitySpec);
			if (!AbilitySpec.IsActive())
			{
				TryActivateAbility(AbilitySpec.Handle);
			}
		}
	}
}

void UT2G1_AbilitySystemComponent::AbilityInputTagReleased(const FGameplayTag& InputTag)
{
	if (!InputTag.IsValid())
	{
		return;
	}
	UE_LOG(LogTemp, Warning, TEXT("AbilityInputTagReleased"));
	for (auto& AbilitySpec : GetActivatableAbilities())
	{
		if (AbilitySpec.DynamicAbilityTags.HasTagExact(InputTag))
		{
			AbilitySpecInputReleased(AbilitySpec);
		}
	}
}



void UT2G1_AbilitySystemComponent::EffectApplied_Implementation(UAbilitySystemComponent* AbilitySystemComponent,
                                                                const FGameplayEffectSpec& EffectSpec, FActiveGameplayEffectHandle ActiveGameplayEffectHandle)
{
	FGameplayTagContainer TagContainer;
	EffectSpec.GetAllAssetTags(TagContainer);
	EffectAssetTags.Broadcast(TagContainer);
	
	for (const auto& Tag : TagContainer)
	{
		GEngine->AddOnScreenDebugMessage(1, 1, FColor::Blue, FString::Printf(TEXT("tag: %s"), *Tag.ToString()));
		
	}
}
