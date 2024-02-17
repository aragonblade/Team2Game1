// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/T2G1_Character.h"

#include "Camera/CameraComponent.h"

AT2G1_Character::AT2G1_Character()
{

	bReplicates = true;
	PrimaryActorTick.bCanEverTick = false;
	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));
	SpringArmComponent->SetupAttachment(RootComponent);
	
	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	CameraComponent->SetupAttachment(SpringArmComponent);
	
}

void AT2G1_Character::BeginDestroy()
{
	Super::BeginDestroy();
	
	
}



