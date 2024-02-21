// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerController/T2G1_PlayerController.h"
#include "EnhancedInputSubsystems.h"

#include "EnhancedInputComponent.h"

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
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent))
	{
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AT2G1_PlayerController::Move);
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &AT2G1_PlayerController::MouseLook);
		// Jumping
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Started, this, &AT2G1_PlayerController::Jump);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &AT2G1_PlayerController::JumpStop);
		// Crouching
		EnhancedInputComponent->BindAction(CrouchAction, ETriggerEvent::Started, this, &AT2G1_PlayerController::Crouch);
		EnhancedInputComponent->BindAction(CrouchAction, ETriggerEvent::Completed, this, &AT2G1_PlayerController::UnCrouch);
	}
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
