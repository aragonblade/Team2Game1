// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerController/T2G1_PlayerController.h"

#include "AbilitySystemBlueprintLibrary.h"
#include "EnhancedInputSubsystems.h"
#include "GameplayTagContainer.h"
#include "GameFramework/Character.h"
#include "GameplayAbility/AbilitySystemComponent/T2G1_AbilitySystemComponent.h"
#include "Input/T2G1_EnhancedInputComponent.h"


AT2G1_PlayerController::AT2G1_PlayerController()
{
	bReplicates = true;
}

void AT2G1_PlayerController::BeginPlay()
{
	Super::BeginPlay();

	if (UEnhancedInputLocalPlayerSubsystem* LocalPlayerSubsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
		LocalPlayerSubsystem->AddMappingContext(InputMappingContext,0);
}

void AT2G1_PlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	if (UT2G1_EnhancedInputComponent* T2G1_EnhancedInputComponent = Cast<UT2G1_EnhancedInputComponent>(InputComponent))
	{
		T2G1_EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AT2G1_PlayerController::Move);
		T2G1_EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &AT2G1_PlayerController::MouseLook);
		// Jumping
		T2G1_EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Started, this, &AT2G1_PlayerController::Jump);
		T2G1_EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &AT2G1_PlayerController::JumpStop);
		// Crouching
		T2G1_EnhancedInputComponent->BindAction(CrouchAction, ETriggerEvent::Started, this, &AT2G1_PlayerController::Crouch);
		T2G1_EnhancedInputComponent->BindAction(CrouchAction, ETriggerEvent::Completed, this, &AT2G1_PlayerController::UnCrouch);

		//T2G1_EnhancedInputComponent->BindAbilityActions(InputConfig, this, &ThisClass::AbilityInputPressed, &ThisClass::AbilityInputReleased, &ThisClass::AbilityInputHeld);
		T2G1_EnhancedInputComponent->BindAbilityActions(InputConfig, this,
			&ThisClass::AbilityInputTagPressed,
			&ThisClass::AbilityInputTagReleased);		
	
	}
}

UT2G1_AbilitySystemComponent* AT2G1_PlayerController::GetASC()
{
	if (T2G1_AbilitySystemComponent == nullptr)
	{
		T2G1_AbilitySystemComponent = Cast<UT2G1_AbilitySystemComponent>(UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(GetPawn<APawn>()));
	}
	return T2G1_AbilitySystemComponent;
}

void AT2G1_PlayerController::Move(const FInputActionValue& InputActionValue)
{
	FVector2d Velocity = InputActionValue.Get<FVector2D>();

	if(GetCharacter() != nullptr)
	{
		const FRotator Rotation = GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);
		const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		GetCharacter()->AddMovementInput(ForwardDirection, Velocity.Y);
		GetCharacter()->AddMovementInput(RightDirection, Velocity.X);
	}
}

void AT2G1_PlayerController::MouseLook(const FInputActionValue& InputActionValue)
{
	const FVector2D LookAxisVector = InputActionValue.Get<FVector2D>();
	AddYawInput(LookAxisVector.X);
	AddPitchInput(-LookAxisVector.Y);

}

void AT2G1_PlayerController::Jump(const FInputActionValue& InputActionValue)
{
	GetCharacter()->Jump();
}

void AT2G1_PlayerController::JumpStop(const FInputActionValue& InputActionValue)
{
	GetCharacter()->StopJumping();
}

void AT2G1_PlayerController::Crouch(const FInputActionValue& InputActionValue)
{
	GetCharacter()->Crouch();
	UE_LOG(LogTemp, Warning, TEXT("Crouch"));
}

void AT2G1_PlayerController::UnCrouch(const FInputActionValue& InputActionValue)
{
	GetCharacter()->UnCrouch();
	UE_LOG(LogTemp, Warning, TEXT("UnCrouch"));
}

void AT2G1_PlayerController::AbilityInputTagPressed(FGameplayTag InputTag)
{
	GetASC()->AbilityInputTagHeld(InputTag);
}

void AT2G1_PlayerController::AbilityInputTagReleased(FGameplayTag InputTag)
{
	GetASC()->AbilityInputTagReleased(InputTag);
}
