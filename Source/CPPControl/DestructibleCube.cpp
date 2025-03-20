#include "DestructibleCube.h"
#include "Components/StaticMeshComponent.h"


ADestructibleCube::ADestructibleCube()
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


void ADestructibleCube::BeginPlay()
{
	Super::BeginPlay();
}


void ADestructibleCube::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


void ADestructibleCube::DestroyObject()
{
	
	Destroy();
}




