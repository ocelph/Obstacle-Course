// Fill out your copyright notice in the Description page of Project Settings.


#include "ReversingPlatform.h"

// Sets default values
AReversingPlatform::AReversingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MovementSpeed = 100.0f;
	ToleranceThreshold = MovementSpeed/10;
	GoalIndex = 0;
	isInReverse = false;
	
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	PlatformMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Platform Mesh"));
	PlatformMesh->SetupAttachment(RootComponent);
	
}

// Called when the game starts or when spawned
void AReversingPlatform::BeginPlay()
{
	Super::BeginPlay();
	
	CurentStartLocation = GetActorLocation();
	Waypoints.Insert(CurentStartLocation, 0);
	
}

// Called every frame
void AReversingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	
	if (Waypoints.Num() == 1)
		return;
	
	if (GoalIndex >= Waypoints.Num())
	{
		isInReverse = true;
		GoalIndex = Waypoints.Num()-1;
	}
	
	if (GoalIndex <= 0)
	{
		isInReverse = false;
		GoalIndex = 0;
	}
	
		
	FVector Direction = Waypoints[GoalIndex] - GetActorLocation();
	// we normalise sth to remove the length. doing this will allow us to have consistent speed
	Direction.Normalize();
	
	Direction = Direction * MovementSpeed * DeltaTime;
	FVector NewLocation = GetActorLocation() + Direction;
	
	if (!isInReverse)
	{
		if (FVector::Distance(Waypoints[GoalIndex], NewLocation) <= ToleranceThreshold)
		{
			NewLocation = Waypoints[GoalIndex];
			GoalIndex++;
		}
	} else
	{
		if (FVector::Distance(Waypoints[GoalIndex], NewLocation) <= ToleranceThreshold)
		{
			NewLocation = Waypoints[GoalIndex];
			GoalIndex--;
			
		}
	}
	
	SetActorLocation(NewLocation);

}

