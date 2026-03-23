// Fill out your copyright notice in the Description page of Project Settings.


#include "LoopingPlatform.h"

// Sets default values
ALoopingPlatform::ALoopingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ALoopingPlatform::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ALoopingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

