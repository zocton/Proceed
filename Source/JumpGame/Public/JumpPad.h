// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "JumpPad.generated.h"

class AJumpGameCharacter;

/**
 * 
 */
UCLASS()
class JUMPGAME_API AJumpPad : public AStaticMeshActor
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UBoxComponent* Collider;

	UFUNCTION() void OnColliderBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION() void OnColliderEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex);

	void CallPlayerJump();

	bool bShouldJump;

	AJumpGameCharacter* Player;
public:
	AJumpPad();
	virtual void BeginPlay() override;
};
