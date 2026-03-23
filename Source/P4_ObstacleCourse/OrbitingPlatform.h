// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "OrbitingPlatform.generated.h"

UCLASS()
class P4_OBSTACLECOURSE_API AOrbitingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AOrbitingPlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* PlatformMesh;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float OrbitSpeed;
	
	// distance from the location which our platform will orbit from
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float OrbitDistance;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float CurrentOrbitAngle;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
