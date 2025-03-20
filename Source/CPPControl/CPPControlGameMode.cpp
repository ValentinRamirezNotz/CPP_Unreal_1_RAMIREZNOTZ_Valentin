// Copyright Epic Games, Inc. All Rights Reserved.

#include "CPPControlGameMode.h"
#include "CPPControlCharacter.h"
#include "UObject/ConstructorHelpers.h"

ACPPControlGameMode::ACPPControlGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
