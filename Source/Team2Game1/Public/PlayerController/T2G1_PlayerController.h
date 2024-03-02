// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "GameplayTagContainer.h"
#include "T2G1_PlayerController.generated.h"

class UT2G1_InputConfig;
class UT2G1_AbilitySystemComponent;
class UInputAction;
struct FInputActionValue;
/**
 * 
 */
class UInputMappingContext;

UCLASS()
class TEAM2GAME1_API AT2G1_PlayerController : public APlayerController
{
	GENERATED_BODY()
	AT2G1_PlayerController();

	

public:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;

	UT2G1_AbilitySystemComponent* GetASC();
	TObjectPtr<UT2G1_AbilitySystemComponent> T2G1_AbilitySystemComponent;
protected:
	void Move(const FInputActionValue& InputActionValue);
	void MouseLook(const FInputActionValue& InputActionValue);
	void Jump(const FInputActionValue& InputActionValue);
	void JumpStop(const FInputActionValue& InputActionValue);
	void Crouch(const FInputActionValue& InputActionValue);
	void UnCrouch(const FInputActionValue& InputActionValue);



	
private:
	UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess = "true"))
	TObjectPtr<UInputMappingContext> InputMappingContext;

	UPROPERTY(EditAnywhere, Category="Input", meta=(AllowPrivateAccess = "true"))
	TObjectPtr<UInputAction> MoveAction;

	UPROPERTY(EditAnywhere, Category= "Input", meta=(AllowPrivateAccess = "true"))
	TObjectPtr<UInputAction> LookAction;
	
	UPROPERTY(EDitAnywhere, Category="Input", meta=(AllowPrivateAccess = "true"))
	TObjectPtr<UInputAction> JumpAction;

	UPROPERTY(EditAnywhere, Category="Input", meta=(AllowPrivateAccess = "true"))
	TObjectPtr<UInputAction> CrouchAction;
	
	UPROPERTY(EditAnywhere, Category="Input", meta=(AllowPrivateAccess = "true"))
	TObjectPtr<UT2G1_InputConfig> InputConfig;


	void AbilityInputTagPressed(FGameplayTag InputTag);
	void AbilityInputTagReleased(FGameplayTag InputTag);
};
	