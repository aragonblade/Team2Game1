// Fill out your copyright notice in the Description page of Project Settings.


#include "GameplayAbility/T2G1_AbilitySystemLibrary.h"

#include "AbilitySystemComponent.h"
#include "GameplayAbilitySpec.h"
#include "GameMode/T2G1_GameMode.h"
#include "GameplayAbility/Data/CharacterClassInfo.h"
#include "Interaction/CombatInterface.h"


bool UT2G1_AbilitySystemLibrary::IsNotFriend(AActor* FirstActor, AActor* SecondActor)
{
	const bool bBothArePlayers = FirstActor->ActorHasTag(FName("Player")) && SecondActor->ActorHasTag(FName("Player"));
	const bool bBothAreEnemies = FirstActor->ActorHasTag(FName("Enemy")) && SecondActor->ActorHasTag(FName("Enemy"));
	const bool bFriends = bBothArePlayers || bBothAreEnemies;
	return !bFriends;
}

void UT2G1_AbilitySystemLibrary::GiveStartupAbilities(const UObject* WorldContextObject, UAbilitySystemComponent* ASC,
	ECharacterClass CharacterClass)
{
	UCharacterClassInfo* CharacterClassInfo = GetCharacterClassInfo(WorldContextObject);
	if (CharacterClassInfo)
	{
		for (auto AbilityClass : CharacterClassInfo->StartupAbilities)
		{
			FGameplayAbilitySpec AbilitySpec = FGameplayAbilitySpec(AbilityClass, 1);
			ASC->GiveAbility(AbilitySpec);
		}
		
	}
}

UCharacterClassInfo* UT2G1_AbilitySystemLibrary::GetCharacterClassInfo(const UObject* WorldContextContext)
{
	if (const AT2G1_GameMode* GameMode = Cast<AT2G1_GameMode>(WorldContextContext->GetWorld()->GetAuthGameMode()))
	{
		return GameMode->CharacterClassInfo;
	}
	return nullptr;
}
