// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseCharacter.h"
#include "T2G1_Character.generated.h"

/**
 * 
 */
UCLASS()
class TEAM2GAME1_API AT2G1_Character : public ABaseCharacter
{
	GENERATED_BODY()
	AT2G1_Character();

public:
	virtual void BeginDestroy() override;
};
