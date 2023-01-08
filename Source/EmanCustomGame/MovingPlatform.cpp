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

	MovePlatform(DeltaTime);
	RotatePlatform(DeltaTime);
}


void AMovingPlatform::MovePlatform(float DeltaTime)
{
#pragma region Return Statements Lecture

	if (ShouldPlatformReturn())
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
	else
	{
		CurrentLocation = GetActorLocation();
		CurrentLocation += (PlatformVelocity * DeltaTime);
		SetActorLocation(CurrentLocation);
	}
}

bool AMovingPlatform::ShouldPlatformReturn()
{
	return (MoveDistance < GetDistanceMoved());
}

float AMovingPlatform::GetDistanceMoved()
{
	return FVector::Dist(StartLocation, GetActorLocation());
}

#pragma endregion

void AMovingPlatform::RotatePlatform(float DeltaTime)
{
	FRotator CurrentRotation = GetActorRotation();

	CurrentRotation += (FRotator(0, 2, 0));

	SetActorRotation(CurrentRotation);

	UE_LOG(LogTemp, Warning, TEXT("%s is rotating"), *GetName());
}