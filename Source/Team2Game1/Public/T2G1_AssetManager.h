// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/AssetManager.h"
#include "T2G1_AssetManager.generated.h"

/**
 * 
 */
UCLASS()
class TEAM2GAME1_API UT2G1_AssetManager : public UAssetManager
{
	GENERATED_BODY()
public:
	static const UT2G1_AssetManager& Get();
	virtual  void StartInitialLoading() override;
private:

	
};
