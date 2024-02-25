// Fill out your copyright notice in the Description page of Project Settings.


#include "GameplayAbility/Data/CharacterClassInfo.h"

FCharacterClassDefaultInfo UCharacterClassInfo::GetCharacterClassDefaultInfo(ECharacterClass CharacterClass)
{
	return CharacterClassDefaultInfo.FindChecked(CharacterClass);
}
