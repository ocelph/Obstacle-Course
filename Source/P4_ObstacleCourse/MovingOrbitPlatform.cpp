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
	OrbitDistance = 750.0f;
	CurrentOrbitAngle = 0.0f;
	
	MovementSpeed = 100.0f;
	ToleranceThreshold = MovementSpeed/10;
}

// Called when the game starts or when spawned
void AMovingOrbitPlatform::BeginPlay()
{
	Super::BeginPlay();
	
	CentreLocation = TargetActor->GetActorLocation();
	
}

// Called every frame
void AMovingOrbitPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	// If no target actor is set then the platform does not orbit
	
	if (!TargetActor)
	{
		UE_LOG(LogTemp, Warning, TEXT("OrbitPlatform: TargetActor is NULL!"));
		return;
	} else
	{
		UE_LOG(LogTemp, Warning, TEXT("OrbitPlatform: TargetActor is %s"), *TargetActor->GetName());
	}
	
	CentreLocation = TargetActor->GetActorLocation();
	
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
	FVector NewLocation = GetActorLocation();
}

