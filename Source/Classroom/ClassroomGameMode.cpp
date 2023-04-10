// Copyright Epic Games, Inc. All Rights Reserved.

#include "ClassroomGameMode.h"
#include "ClassroomCharacter.h"
#include "UObject/ConstructorHelpers.h"

AClassroomGameMode::AClassroomGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
