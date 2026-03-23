// Fill out your copyright notice in the Description page of Project Settings.


#include "SecurityCamera.h"
#include "GameFramework/Character.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
ASecurityCamera::ASecurityCamera()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>("RootComponent");
	CameraMesh = CreateDefaultSubobject<UStaticMeshComponent>("Camera Mesh");
	CameraMesh-> SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ASecurityCamera::BeginPlay()
{
	Super::BeginPlay();
	
	// GetFirstPlayerController(), as this will reference our player
	TargetCharacter =GetWorld()->GetFirstPlayerController()-> GetCharacter();
}

// Called every frame
void ASecurityCamera::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	FQuat QuatRotation = FQuat(UKismetMathLibrary::FindLookAtRotation(GetActorLocation(), TargetCharacter->GetActorLocation()));
	
	SetActorRotation(QuatRotation);

}

