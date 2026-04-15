// Fill out your copyright notice in the Description page of Project Settings.

#include "MovingPlatform.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = Mesh;

	MoveSpeed = 100.f;
	MaxRange = 300.f;

	bMovingForward = true;

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

	FVector CurrentLocation = GetActorLocation();

	float Direction = bMovingForward ? 1.f : -1.f;

	FVector NewLocation = CurrentLocation + FVector(Direction * MoveSpeed * DeltaTime, 0.f, 0.f);

	SetActorLocation(NewLocation);

	float Distance = FVector::Dist(StartLocation, NewLocation);

	if (Distance >= MaxRange)
	{
		bMovingForward = !bMovingForward;
	}

}

