// Fill out your copyright notice in the Description page of Project Settings.


#include "T2G1_AssetManager.h"

#include "AbilitySystemGlobals.h"
#include "FT2G1_GameplayTags.h"


const UT2G1_AssetManager& UT2G1_AssetManager::Get()
{
	check(GEngine->AssetManager);

	return *Cast<UT2G1_AssetManager>(GEngine->AssetManager);
}

void UT2G1_AssetManager::StartInitialLoading()
{
	Super::StartInitialLoading();
	
	FT2G1_GameplayTags::InitializeNativeGameplayTags();
	UAbilitySystemGlobals::Get().InitGlobalData();
}
