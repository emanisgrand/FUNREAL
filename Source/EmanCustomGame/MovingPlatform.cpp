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

	MovePlatform(DeltaTime);
	RotatePlatform(DeltaTime);
}

#pragma region Member Function Lecture
void AMovingPlatform::MovePlatform(float DeltaTime)
{
	// Capture current actor location
	CurrentLocation = GetActorLocation();

	CurrentLocation += (PlatformVelocity * DeltaTime);

	SetActorLocation(CurrentLocation);

	// track distance traveled.
	float DistanceTraveled = FVector::Dist(StartLocation, CurrentLocation);

	if (DistanceTraveled > MoveDistance)
	{
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

void AMovingPlatform::RotatePlatform(float DeltaTime)
{
	FRotator CurrentRotation = GetActorRotation();

	CurrentRotation += (FRotator(0, 2, 0));

	SetActorRotation(CurrentRotation);

	UE_LOG(LogTemp, Warning, TEXT("%s is rotating"), *GetName());
}
#pragma endregion