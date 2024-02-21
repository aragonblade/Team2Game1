// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"

/**
 * 
 */
struct TEAM2GAME1_API FT2G1_GameplayTags
{
public:
 static const FT2G1_GameplayTags& Get() { return GameplayTags; }
 static void InitializeNativeGameplayTags();

 //vital
 FGameplayTag Attributes_Vital_Health;
 FGameplayTag Attributes_Vital_Mana;

 //primary
 FGameplayTag Attributes_Primary_Strength;
 FGameplayTag Attributes_Primary_Intelligence;
 FGameplayTag Attributes_Primary_Agility;
 FGameplayTag Attributes_Primary_Resilience;
 FGameplayTag Attributes_Primary_Vigor;

 //Secondary
 FGameplayTag Attributes_Secondary_MaxMana;
 FGameplayTag Attributes_Secondary_MaxHealth;
 FGameplayTag Attributes_Secondary_Armour;
 FGameplayTag Attributes_Secondary_ArmourPenetration;
 FGameplayTag Attributes_Secondary_BlockChance;
 FGameplayTag Attributes_Secondary_CriticalHitChance;
 FGameplayTag Attributes_Secondary_CriticalHitDamage;
 FGameplayTag Attributes_Secondary_HealthRegen;
 FGameplayTag Attributes_Secondary_ManaRegen;


 //Input
 FGameplayTag InputTag_LMB;
 FGameplayTag InputTag_RMB;
 FGameplayTag InputTag_1;
 FGameplayTag InputTag_2;
 FGameplayTag InputTag_3;
 FGameplayTag InputTag_4;
 FGameplayTag InputTag_Space;

//damge
 FGameplayTag FireAbility;
 FGameplayTag SpellAbility;

private:
 static FT2G1_GameplayTags GameplayTags;
 
};
