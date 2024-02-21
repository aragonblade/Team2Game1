// Fill out your copyright notice in the Description page of Project Settings.


#include "Animations/T2G1_AnimInstance.h"

#include "KismetAnimationLibrary.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"

UT2G1_AnimInstance::UT2G1_AnimInstance(): Speed(0), bEnableJump(false)
{
}

void UT2G1_AnimInstance::NativeBeginPlay()
{
	Super::NativeBeginPlay();
	OwningCharacter = Cast<ACharacter>(TryGetPawnOwner());
	MovementComponent = OwningCharacter->GetCharacterMovement();
	OwningPlayerController = Cast<APlayerController>(OwningCharacter->GetController());
	
	check(OwningCharacter)

}

void UT2G1_AnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);
	if (OwningCharacter)
	{

		
		const FRotator Rotation = OwningCharacter->GetActorRotation();
		//FRotator DeltaRotation = Rotation - LastRotation;
		MovementVelocity = OwningCharacter->GetVelocity();
		
		Speed = MovementVelocity.Size();
		if (MovementComponent->GetCurrentAcceleration() != FVector::ZeroVector && Speed > 3.0f)
		{
			bShouldMove = true;
		}
		else
		{
			bShouldMove = false;
		}

		

		Direction = UKismetAnimationLibrary::CalculateDirection(MovementVelocity, Rotation);
		
		bCrouching = MovementComponent->IsCrouching();
		bEnableJump = MovementComponent->IsFalling();
	}
	
}
