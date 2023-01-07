// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Get Player Location?

}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	// Capture current actor location
	FVector CurrentLocation = GetActorLocation();
	// Add result of FVector value * deltatime to CurrentLocation
	CurrentLocation += (PlatformVelocity * DeltaTime);
	// Update Actor location
	SetActorLocation(CurrentLocation);

	// Send the platform back if it's gone too far
		// check how far the platform's moved
		// send back if it's gone too far

}

