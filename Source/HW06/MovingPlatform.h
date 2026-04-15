// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

UCLASS()
class HW06_API AMovingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingPlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
    // 메시
    UPROPERTY(VisibleAnywhere)
    UStaticMeshComponent* Mesh;

    // 시작 위치
    FVector StartLocation;

    // 이동 방향
    bool bMovingForward;

public:
    // 이동 속도
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
    float MoveSpeed;

    // 이동 범위
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
    float MaxRange;

};
