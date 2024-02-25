// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayAbility/Abilities/T2G1_GameplayAbility.h"
#include "T2G1_DamgeGameplayAbility.generated.h"

struct FTaggedMontage;
/**
 * 
 */
UCLASS()
class TEAM2GAME1_API UT2G1_DamgeGameplayAbility : public UT2G1_GameplayAbility
{
	GENERATED_BODY()
protected:	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<UGameplayEffect> DamageEffectClass;

	/*UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category= "Damage")
	FScalableFloat Damage;*/
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TMap<FGameplayTag, FScalableFloat> DamageTypes;

	
	
public:
	UFUNCTION(BlueprintCallable, Category= "Cause Damage")
	void CauseDamage(AActor* TargetActor);

	UFUNCTION(BlueprintPure, Category = "Attack|montage")
	FTaggedMontage GetRandomTaggedMontageFromArray(const TArray<FTaggedMontage>& TaggedMontages);
};
