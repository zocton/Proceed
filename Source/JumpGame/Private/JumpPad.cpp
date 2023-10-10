// Fill out your copyright notice in the Description page of Project Settings.


#include "JumpPad.h"
#include "Components/BoxComponent.h"
#include "GameFramework/JumpGameCharacter.h"
#include "Kismet/GameplayStatics.h"

AJumpPad::AJumpPad()
{
	Collider = CreateDefaultSubobject<UBoxComponent>(FName("BoxCollision"));
	Collider->SetupAttachment(RootComponent);
	Collider->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	Collider->SetGenerateOverlapEvents(true);
}

void AJumpPad::BeginPlay()
{
	Super::BeginPlay();

	Collider->OnComponentBeginOverlap.AddDynamic(this, &AJumpPad::OnColliderBeginOverlap);
	Collider->OnComponentEndOverlap.AddDynamic(this, &AJumpPad::OnColliderEndOverlap);
	
	Player = Cast<AJumpGameCharacter>(UGameplayStatics::GetActorOfClass(GetWorld(), AJumpGameCharacter::StaticClass()));
}

void AJumpPad::OnColliderBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (!OtherActor->IsA<AJumpGameCharacter>())	return;

	bShouldJump = true;
	FTimerHandle JumpPadHandle;
	GetWorldTimerManager().SetTimer(JumpPadHandle, this, &AJumpPad::CallPlayerJump, 1.0f, false);
}

void AJumpPad::OnColliderEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex)
{
	bShouldJump = false;
}

void AJumpPad::CallPlayerJump()
{
	if (bShouldJump) Player->JumpPadInteraction();
}