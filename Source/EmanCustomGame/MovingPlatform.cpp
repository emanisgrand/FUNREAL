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
	UE_LOG(LogTemp, Display, TEXT("Check this value out %f"), MoveDistance);
	UE_LOG(LogTemp, Warning, TEXT("Check this value out %f"), MoveDistance);
	UE_LOG(LogTemp, Error, TEXT("Check this value out %f"), MoveDistance);
	
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

#pragma region FString Lecture
		FString name = GetName();
		float overShoot = (DistanceTraveled - MoveDistance);
		UE_LOG(LogTemp, Warning, TEXT("%s Shot-over by %f"),*name, overShoot);
#pragma endregion 

		// Cache the normal of the actor's current direction 
		FVector MoveDirection = PlatformVelocity.GetSafeNormal();
		// Increment the start location in the direction the platform is moving by the distance each step
		StartLocation += (MoveDirection * MoveDistance);
		// update actor location with updated start location.
		SetActorLocation(StartLocation);
		// Reverse directions.
		PlatformVelocity = -PlatformVelocity;
	}	
}

