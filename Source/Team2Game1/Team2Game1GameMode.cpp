// Copyright Epic Games, Inc. All Rights Reserved.

#include "Team2Game1GameMode.h"
#include "Team2Game1Character.h"
#include "UObject/ConstructorHelpers.h"

ATeam2Game1GameMode::ATeam2Game1GameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
