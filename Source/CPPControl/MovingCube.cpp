// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingCube.h"

AMovingCube::AMovingCube()
{
    PrimaryActorTick.bCanEverTick = true;

    CubeMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CubeMesh"));
    RootComponent = CubeMesh;

    static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeMeshAsset(TEXT("/Engine/BasicShapes/Cube.Cube"));
    if (CubeMeshAsset.Succeeded())
    {
        CubeMesh->SetStaticMesh(CubeMeshAsset.Object);
    }
}

void AMovingCube::BeginPlay()
{
    Super::BeginPlay();
}

void AMovingCube::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    TimeElapsed += DeltaTime;

    FVector NewLocation = GetActorLocation();
    NewLocation.Z += Amplitude * FMath::Sin(Speed * TimeElapsed);

    float X = Radius * FMath::Cos(Speed * TimeElapsed);
    float Y = Radius * FMath::Sin(Speed * TimeElapsed);

    NewLocation.X += X;
    NewLocation.Y += Y;

    SetActorLocation(NewLocation);
}
