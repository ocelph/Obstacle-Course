// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LoopingPlatform.generated.h"

UCLASS()
class P4_OBSTACLECOURSE_API ALoopingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALoopingPlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(Editanywhere)
	UStaticMeshComponent* PlatformMesh;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MovementSpeed;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float ToleranceThreshold;
	
	//  n number of waypoints to move between
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FVector> Waypoints;
	
	// a variable to indicate the current index of the waypoint array we are up to
	int32 GoalIndex;
	
	UPROPERTY()
	FVector StartLocation;
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
