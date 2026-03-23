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
	
	if (Waypoints.Num() <= 1)
		return;
	
	if (GoalIndex >= Waypoints.Num())
	{
		GoalIndex = 0;
	}
		
	// FOR MOVING POINT
	FVector Direction = Waypoints[GoalIndex] - CentreLocation;
	
	// we normalise sth to remove the length. doing this will allow us to have consistent speed
	Direction.Normalize();
	
	Direction = Direction * MovementSpeed * DeltaTime;
	CentreLocation = CentreLocation + Direction;
	
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
	
	float x = CentreLocation.X + OrbitDistance * FMath::Cos(Radians);
	float y = CentreLocation.Y + OrbitDistance * FMath::Sin(Radians);

	SetActorLocation(FVector(x,y, CentreLocation.Z));

}

