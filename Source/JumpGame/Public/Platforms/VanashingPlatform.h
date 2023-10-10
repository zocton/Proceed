// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "VanashingPlatform.generated.h"

/**
 * 
 */
UCLASS()
class JUMPGAME_API AVanashingPlatform : public AStaticMeshActor
{
	GENERATED_BODY()
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UBoxComponent* Collider;
};
