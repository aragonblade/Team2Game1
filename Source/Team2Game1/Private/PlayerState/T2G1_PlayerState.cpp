// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerState/T2G1_PlayerState.h"

#include "Attributes/T2G1_AttributeSet.h"
#include "GameplayAbility/AbilitySystemComponent/T2G1_AbilitySystemComponent.h"
#include "Net/UnrealNetwork.h"

AT2G1_PlayerState::AT2G1_PlayerState()
{
	AbilitySystemComponent = CreateDefaultSubobject<UT2G1_AbilitySystemComponent>("Ability System Component");
	AbilitySystemComponent->SetIsReplicated(true);

	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);
	AttributeSet = CreateDefaultSubobject<UT2G1_AttributeSet>("Attribute Set");

	NetUpdateFrequency = 100.f;
	
}

void AT2G1_PlayerState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AT2G1_PlayerState, Level);
	
}

UAbilitySystemComponent* AT2G1_PlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

int32 AT2G1_PlayerState::GetPlayerLevel() const
{
	return Level;
}

void AT2G1_PlayerState::OnRep_Level(int32 OldLevel)
{
}
