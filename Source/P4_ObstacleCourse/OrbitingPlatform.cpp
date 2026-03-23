// Fill out your copyright notice in the Description page of Project Settings.


#include "OrbitingPlatform.h"

// Sets default values
AOrbitingPlatform::AOrbitingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>("RootComponent");
	PlatformMesh = CreateDefaultSubobject<UStaticMeshComponent>("PlatformMesh");
	PlatformMesh-> SetupAttachment(RootComponent);
	
	OrbitSpeed = 90.0f;
	OrbitDistance = 4.0f;
	CurrentOrbitAngle = 0.0f;
	
	
}

// Called when the game starts or when spawned
void AOrbitingPlatform::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AOrbitingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	// To calculate our new position, we need to work out what angle we should be at from our starting position based on our speed and current angle.
	// we update our current orbit angle by adding our speed times delta time. We then convert this to radians, as we’ll need them for the next operation
	
	CurrentOrbitAngle = CurrentOrbitAngle + (DeltaTime * OrbitSpeed);
	
	if (CurrentOrbitAngle >= 360)
	{
		CurrentOrbitAngle = CurrentOrbitAngle - 360;
	}
	
	float Radians = FMath::DegreesToRadians(CurrentOrbitAngle);
	
	float x = GetActorLocation().X + OrbitDistance * FMath::Cos(Radians);
	float y = GetActorLocation().Y + OrbitDistance * FMath::Sin(Radians);

	SetActorLocation(FVector(x,y, GetActorLocation().Z));
}

