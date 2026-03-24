// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingOrbitPlatform.h"

// Sets default values
AMovingOrbitPlatform::AMovingOrbitPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	PlatformMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Platform Mesh"));
	PlatformMesh->SetupAttachment(RootComponent);
	
	OrbitSpeed = 90.0f;
	OrbitDistance = 4.0f;
	CurrentOrbitAngle = 0.0f;
	
	MovementSpeed = 100.0f;
	ToleranceThreshold = MovementSpeed/10;
	GoalIndex = 0;
}

// Called when the game starts or when spawned
void AMovingOrbitPlatform::BeginPlay()
{
	Super::BeginPlay();
	
	StartLocation = GetActorLocation();
	Waypoints.Add(StartLocation);
	CentreLocation = StartLocation;
	
}

// Called every frame
void AMovingOrbitPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	// FOR MOVING POINT
	if (Waypoints.Num() == 1)
		return;
	
	if (GoalIndex >= Waypoints.Num())
	{
		GoalIndex = 0;
	}
		
	FVector Direction = Waypoints[GoalIndex] - GetActorLocation();
	// we normalise sth to remove the length. doing this will allow us to have consistent speed
	Direction.Normalize();
	
	Direction = Direction * MovementSpeed * DeltaTime;
	FVector NewLocation = GetActorLocation() + Direction;
	
	FVector CentreDirection = Waypoints[GoalIndex] - CentreLocation;
	CentreDirection.Normalize();

	CentreDirection *= MovementSpeed * DeltaTime;
	CentreLocation += CentreDirection;
	
	// Fix 1: Just going from initial posi to next waypoint
	// if (FVector::Distance(Waypoints[GoalIndex], NewLocation) <= ToleranceThreshold)
	// {
	// 	NewLocation = Waypoints[GoalIndex];
	// 	GoalIndex++;
	// }
	//
	// Question: Is it not working because of the 4.0 orbit distance?
	
	
	
	if (FVector::Distance(Waypoints[GoalIndex], CentreLocation) <= ToleranceThreshold)
	{
		CentreLocation = Waypoints[GoalIndex];
		GoalIndex++;
	}
	
	// FOR ORBITTING MOVEMENT
	CurrentOrbitAngle = CurrentOrbitAngle + (DeltaTime * OrbitSpeed);
	
	if (CurrentOrbitAngle >= 360)
	{
		CurrentOrbitAngle = CurrentOrbitAngle - 360;
	}
	
	float Radians = FMath::DegreesToRadians(CurrentOrbitAngle);
	
	float x = NewLocation.X + OrbitDistance * FMath::Cos(Radians);
	float y = NewLocation.Y + OrbitDistance * FMath::Sin(Radians);
	
	
	// Fix 2: Not orbitting, Just moving up and down
	// float x = CentreLocation.X + OrbitDistance * FMath::Cos(Radians);
	// float y = CentreLocation.Y + OrbitDistance * FMath::Sin(Radians);
	//
	// Question: I didn't understand why it is not orbiting when i do this

	SetActorLocation(FVector(x,y, NewLocation.Z));
}

