// Fill out your copyright notice in the Description page of Project Settings.


#include "WaypointPlatform.h"

// Sets default values
AWaypointPlatform::AWaypointPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	MovementSpeed = 100.0f;
	ToleranceThreshold = MovementSpeed/10;
	GoalIndex = 0;
	
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	PlatformMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Platform Mesh"));
	PlatformMesh->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AWaypointPlatform::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AWaypointPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	if (Waypoints.Num() == 0 || GoalIndex >= Waypoints.Num())
		return;
	
	FVector Direction = Waypoints[GoalIndex] - GetActorLocation();
	// we normalise sth to remove the length. doing this will allow us to have consistent speed
	Direction.Normalize();
	
	Direction = Direction * MovementSpeed * DeltaTime;
	FVector NewLocation = GetActorLocation() + Direction;
	
	if (FVector::Distance(Waypoints[GoalIndex], NewLocation) <= ToleranceThreshold)
	{
		NewLocation = Waypoints[GoalIndex];
		GoalIndex++;
	}
	SetActorLocation(NewLocation);
}

