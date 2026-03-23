// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HorizontalPlatform.generated.h"

UCLASS()
class P4_OBSTACLECOURSE_API AHorizontalPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AHorizontalPlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// how fast the platform will move and how far it will travel before returning
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float MovementSpeed;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MovementDistance;

	// keeps track of where we started and where we're trying to go
	UPROPERTY()
		FVector PreviousStartLocation;
	UPROPERTY()
	FVector CurrentGoalLocation;
	
	// helps us 'snap' to the final place (if there are anything rounding errors with speed, distance and time)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float ToleranceThreshold;

	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* PlatformMesh;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
