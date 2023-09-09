// Copyright Epic Games, Inc. All Rights Reserved.

#include "transformogusGameMode.h"
#include "transformogusCharacter.h"
#include "UObject/ConstructorHelpers.h"

AtransformogusGameMode::AtransformogusGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
