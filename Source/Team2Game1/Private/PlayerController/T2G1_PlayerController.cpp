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
