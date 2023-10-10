// Copyright Epic Games, Inc. All Rights Reserved.

#include "GameFramework/JumpGameGameMode.h"
#include "GameFramework/JumpGameCharacter.h"
#include "UObject/ConstructorHelpers.h"

AJumpGameGameMode::AJumpGameGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
