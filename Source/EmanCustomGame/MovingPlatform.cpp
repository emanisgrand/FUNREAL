// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{ 	
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();	
	StartLocation = GetActorLocation();
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Capture current actor location
	CurrentLocation = GetActorLocation();

	CurrentLocation += (PlatformVelocity * DeltaTime);

	SetActorLocation(CurrentLocation);

	// track distance traveled.
	float DistanceTraveled = FVector::Dist(StartLocation, CurrentLocation);
	
	if (DistanceTraveled > MoveDistance)
	{
		PlatformVelocity = -PlatformVelocity;
		// set the starting location equal to its current location to reset the 
		// distance traveled.
		StartLocation = CurrentLocation;
	}	
}

