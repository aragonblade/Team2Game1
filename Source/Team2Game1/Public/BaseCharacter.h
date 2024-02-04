// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameplayEffect.h"
#include "GameFramework/Character.h"
#include "BaseCharacter.generated.h"

class UAbilitySystemComponent;
class UAttributeSet;

UCLASS(Abstract)
class TEAM2GAME1_API ABaseCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:

	ABaseCharacter();
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	UAttributeSet* GetAttributeSet() const { return AttributeSet; }
	virtual void InitializeDefaultAttributes()const;

private:
	UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess = "true"))
	TObjectPtr<USkeletalMeshComponent> CharacterMesh;

	UPROPERTY(BlueprintReadOnly, meta=(AllowPrivateAccess = "true"))
	TObjectPtr<UAttributeSet> AttributeSet;

	UPROPERTY(BlueprintReadOnly, meta=(AllowPrivateAccess ="true"))
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY(EditAnywhere, Category="Attributes")
	TSubclassOf<UGameplayEffect> DefaultAttributes;
	
protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	
protected:
	virtual void InitAbilityActorInfo();

	virtual void ApplyEffectToSelf(TSubclassOf<UGameplayEffect> AttributesGameplayEffect, float Level) const;
	
};
