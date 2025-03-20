#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Destructible.h" 
#include "DestructibleCube.generated.h"

UCLASS()
class CPPCONTROL_API ADestructibleCube : public AActor, public IDestructible
{
	GENERATED_BODY()

public:
	
	ADestructibleCube();

protected:
	
	virtual void BeginPlay() override;

public:
	
	virtual void Tick(float DeltaTime) override;

	
	virtual void DestroyObject() override;

private:
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* CubeMesh;  
};

