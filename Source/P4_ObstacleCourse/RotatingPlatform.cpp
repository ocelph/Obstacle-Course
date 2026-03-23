// Fill out your copyright notice in the Description page of Project Settings.


#include "RotatingPlatform.h"

// Sets default values
ARotatingPlatform::ARotatingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	PlatformMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Platform Mesh"));
	PlatformMesh->SetupAttachment(RootComponent);
	
	RotationSpeed = 200.0f;
	CurrentRotation = 0.0f;  //  tracks the current rotation of the platform

}

// Called when the game starts or when spawned
void ARotatingPlatform::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARotatingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	// we’ll update our current rotation based on the rotation speed and delta time. 
	// Every full rotation (360deg) we’ll subtract 360, putting us back at 0
	CurrentRotation = CurrentRotation + (RotationSpeed * DeltaTime);
	
	if (CurrentRotation>= 360)
	{
		CurrentRotation -= 360;
	}
	
	//  FRotator, Rotation, uses our current rotation to spin around the Yaw (the up axis). This spins it in place. 
	FRotator Rotation = FRotator(0, CurrentRotation, 0);
	SetActorRotation(Rotation);
}

