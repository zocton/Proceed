// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "TranslatingPlatform.generated.h"

/**
 * 
 */
UCLASS()
class JUMPGAME_API ATranslatingPlatform : public AStaticMeshActor
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Translation, meta = (AllowPrivateAccess = "true"))
	float TranslationSpeed = 10.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Translation, meta = (AllowPrivateAccess = "true"))
	AActor* PointA;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Translation, meta = (AllowPrivateAccess = "true"))
	AActor* PointB;

	bool bSwapDirection = false;
public:
	ATranslatingPlatform();

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaSeconds) override;
};
