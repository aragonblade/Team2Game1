// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/EnemyBase.h"

#include "Attributes/T2G1_AttributeSet.h"
#include "GameplayAbility/AbilitySystemComponent/T2G1_AbilitySystemComponent.h"

AEnemyBase::AEnemyBase()
{
	GetMesh()->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);

	AbilitySystemComponent = CreateDefaultSubobject<UT2G1_AbilitySystemComponent>("Ability System Component");
	AbilitySystemComponent->SetIsReplicated(true);

	AttributeSet = CreateDefaultSubobject<UT2G1_AttributeSet>("Attribute Set");
	
}
