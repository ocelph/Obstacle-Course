// Fill out your copyright notice in the Description page of Project Settings.


#include "HorizontalPlatform.h"

// Sets default values
AHorizontalPlatform::AHorizontalPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	MovementSpeed = 100.0f;
	MovementDistance = 1000.0f;
	ToleranceThreshold = MovementSpeed/10;
	
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	PlatformMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Platform Mesh"));
	PlatformMesh->SetupAttachment(RootComponent);
	
}

// Called when the game starts or when spawned
void AHorizontalPlatform::BeginPlay()
{
	Super::BeginPlay();
	
	
	//  we need to setup the location variables in BeginPlay to ensure that we already have a position in the world
	PreviousStartLocation = GetActorLocation();
	CurrentGoalLocation = GetActorLocation() + FVector(MovementDistance,0,0);
	//  hard-coded the distance to be on the X-Axis. This is the world forward direction
}

// Called every frame (this is where the movement code will occur)
void AHorizontalPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	// Destination Minus Origin
	FVector Direction = CurrentGoalLocation - GetActorLocation();
	Direction.Normalize();
	// we normalise the result to be a unit vector because we only want the direction and not the distance
	
	
	Direction = Direction * MovementSpeed * DeltaTime;  
	FVector NewLocation = GetActorLocation() + Direction;

	
	// check if we are “close enough” to our goal location. If we are then we snap to it, and reset our goal and starting location
	// FVector::Distance(CurrentGoalLocation, NewLocation) gives the distance between the 2 parameters
	if (FVector::Distance(CurrentGoalLocation,NewLocation) <= ToleranceThreshold)
	{
		NewLocation = CurrentGoalLocation;
		CurrentGoalLocation = PreviousStartLocation;
		PreviousStartLocation = NewLocation;
	}
	SetActorLocation(NewLocation);
	
}

