// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/T2G1_Character.h"

#include "Camera/CameraComponent.h"
#include "GameplayAbility/AbilitySystemComponent/T2G1_AbilitySystemComponent.h"
#include "PlayerController/T2G1_PlayerController.h"
#include "PlayerState/T2G1_PlayerState.h"

class AT2G1_PlayerController;

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

//this function is called when the character is possessed by a controller on the server
void AT2G1_Character::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
	InitAbilityActorInfo();
	AddCharacterAbilities();
	
	UE_LOG(LogTemp, Warning, TEXT("PossessedBy"));
}

void AT2G1_Character::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();
	// init ability actor info for client, replicated from server
	InitAbilityActorInfo();
}

int32 AT2G1_Character::GetPlayerLevel()
{
	const AT2G1_PlayerState* T2G1PlayerState = GetPlayerState<AT2G1_PlayerState>();
	check(T2G1PlayerState);
	return T2G1PlayerState->GetPlayerLevel();
}

void AT2G1_Character::InitAbilityActorInfo()
{
	//get the player state of the character
	AT2G1_PlayerState* T2G1PlayerState = GetPlayerState<AT2G1_PlayerState>();
	check(T2G1PlayerState);
	//initialize the ability actor info
	T2G1PlayerState->GetAbilitySystemComponent()->InitAbilityActorInfo(T2G1PlayerState, this);
	Cast<UT2G1_AbilitySystemComponent>(T2G1PlayerState->GetAbilitySystemComponent())->AbilityActorInfoSet();
	AbilitySystemComponent = T2G1PlayerState->GetAbilitySystemComponent();
	AttributeSet = T2G1PlayerState->GetAttributeSet();
	
	if (AT2G1_PlayerController* T2G1PlayerController =	Cast<AT2G1_PlayerController>(GetController()))
	{
		//todo: create HUD for player
	}

	//todo: Init default attributes
	
}



