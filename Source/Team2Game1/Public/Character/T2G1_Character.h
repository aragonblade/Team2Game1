// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "T2G1CharacterBase.h"
#include "T2G1_Character.generated.h"

/**
 * 
 */
UCLASS()
class TEAM2GAME1_API AT2G1_Character : public AT2G1CharacterBase
{
	GENERATED_BODY()
	

public:
	AT2G1_Character();
	virtual void BeginDestroy() override;

	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState() override;
	virtual int32 GetPlayerLevel() override;
private:
	virtual void InitAbilityActorInfo();
};
