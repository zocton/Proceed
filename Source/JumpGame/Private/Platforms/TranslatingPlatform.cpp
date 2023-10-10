// Fill out your copyright notice in the Description page of Project Settings.


#include "Platforms/TranslatingPlatform.h"
#include "Math/UnrealMathUtility.h"

ATranslatingPlatform::ATranslatingPlatform()
{
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true;

	GetStaticMeshComponent()->SetComponentTickEnabled(true);

	GetStaticMeshComponent()->SetMobility(EComponentMobility::Movable);
	SetMobility(EComponentMobility::Movable);
}

void ATranslatingPlatform::BeginPlay()
{
	Super::BeginPlay();

	SetActorTickEnabled(true);
}

void ATranslatingPlatform::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	if (GetActorLocation().Equals(!bSwapDirection ? PointA->GetActorLocation() : PointB->GetActorLocation(), 1.0f))
	{
		bSwapDirection = !bSwapDirection;
	}

	FVector InterpLocation = FMath::VInterpTo(GetActorLocation(), !bSwapDirection ? PointA->GetActorLocation() : PointB->GetActorLocation(), DeltaSeconds, TranslationSpeed);

	SetActorLocation(InterpLocation);
}