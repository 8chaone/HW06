// Fill out your copyright notice in the Description page of Project Settings.


#include "RotatingActor.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
ARotatingActor::ARotatingActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


    // 메시 생성
    Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
    RootComponent = Mesh;

    // 기본 회전값 (초당 100도 Y축 회전)
    RotationSpeed = FRotator(0.f, 100.f, 0.f);

}

// Called when the game starts or when spawned
void ARotatingActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARotatingActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

    AddActorLocalRotation(RotationSpeed * DeltaTime);

}

