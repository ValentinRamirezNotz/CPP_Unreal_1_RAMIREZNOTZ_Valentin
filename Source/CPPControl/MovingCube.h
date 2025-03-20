// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingCube.generated.h"

UCLASS()
class CPPCONTROL_API AMovingCube : public AActor
{
    GENERATED_BODY()

public:
    AMovingCube();

protected:
    virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;

private:
    UPROPERTY(VisibleAnywhere)
    UStaticMeshComponent* CubeMesh;

    UPROPERTY(EditAnywhere, Category = "Oscillation")
    float Speed = 1.0f;

    UPROPERTY(EditAnywhere, Category = "Oscillation")
    float Amplitude = 50.0f;

    UPROPERTY(EditAnywhere, Category = "Movement")
    float Radius = 100.0f;

    float TimeElapsed = 0.0f;
};