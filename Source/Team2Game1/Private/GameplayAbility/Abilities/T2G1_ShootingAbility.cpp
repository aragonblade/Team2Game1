// Fill out your copyright notice in the Description page of Project Settings.


#include "GameplayAbility/Abilities/T2G1_ShootingAbility.h"

#include "Interaction/CombatInterface.h"

void UT2G1_ShootingAbility::ActivateAbility(const FGameplayAbilitySpecHandle Handle,
                                            const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo,
                                            const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);
}

void UT2G1_ShootingAbility::SpawnProjectile(const FVector& ProjectileTargetLocation, const FGameplayTag& SocketTag,
                                            bool bOverridePitch, float PitchOverride)
{
	const bool bIsServer = GetAvatarActorFromActorInfo()->HasAuthority();

	UE_LOG(LogTemp, Warning, TEXT("Fire gun: SpawnProjectile"));
		
	if (!bIsServer)
	{
		return;
	}
	//TODO: Spawn projectile following the look direction of the player
	const FVector SocketLocation = ICombatInterface::Execute_GetCombatSocketLocation(GetAvatarActorFromActorInfo(), SocketTag);
	
	
}
