// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "T2G1_AnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class TEAM2GAME1_API UT2G1_AnimInstance : public UAnimInstance
{
	GENERATED_BODY()
public:
	UT2G1_AnimInstance();
	
	friend class AT2G1_PlayerController;

	virtual void NativeBeginPlay() override;
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;;

private:
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Movement", meta = (AllowPrivateAccess = "true"))
	float Speed;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Movement", meta = (AllowPrivateAccess = "true"))
	float Direction;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Movement", meta = (AllowPrivateaccess = "true"))
	bool bEnableJump;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Movement", meta = (AllowPrivateaccess = "true"))
	bool bJumping;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Movement", meta = (AllowPrivateaccess = "true"))
	bool bCrouching;
	
	TObjectPtr<ACharacter> OwningCharacter;
	FRotator LastRotation;
};
