// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayAbility/Abilities/T2G1_DamgeGameplayAbility.h"
#include "T2G1_ShootingAbility.generated.h"

class AT2G1_Projectile;
/**
 * 
 */
UCLASS()
class TEAM2GAME1_API UT2G1_ShootingAbility : public UT2G1_DamgeGameplayAbility
{
	GENERATED_BODY()

public:
	virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData) override;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSubclassOf<AT2G1_Projectile> ProjectileClass;

	UFUNCTION(BlueprintCallable, Category= Projectile)
	void SpawnProjectile(const FVector& ProjectileTargetLocation, const FGameplayTag& SocketTag, bool bOverridePitch = false, float PitchOverride = 0);
};
