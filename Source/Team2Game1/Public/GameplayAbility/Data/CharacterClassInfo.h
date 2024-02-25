// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "CharacterClassInfo.generated.h"


class UGameplayAbility;
class UGameplayEffect;
class UCharacterClassInfo;
UENUM(BlueprintType)
enum class ECharacterClass : uint8
{
	Elf,
	Ork,
	Human,
	Dwarf
};

USTRUCT(BlueprintType)
struct FCharacterClassDefaultInfo
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, Category = "Class Defaults")
	TSubclassOf<UGameplayEffect> PrimaryAttributes;

	UPROPERTY(EditDefaultsOnly, Category = "Class Defaults")
	TArray<TSubclassOf<UGameplayAbility>> StartupAbilities;
};


UCLASS()
class TEAM2GAME1_API UCharacterClassInfo : public UDataAsset
{
	GENERATED_BODY()

public:

	UPROPERTY(EditDefaultsOnly, Category = "Character Class Defaults")
	TMap<ECharacterClass, FCharacterClassDefaultInfo> CharacterClassDefaultInfo;

	UPROPERTY(EditDefaultsOnly, Category= "Common Ability")
	TArray<TSubclassOf<UGameplayAbility>> StartupAbilities;
	
	FCharacterClassDefaultInfo GetCharacterClassDefaultInfo(ECharacterClass CharacterClass);
	
};
