#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Camera/CameraComponent.h"  
#include "Destructible.h"  
#include "DestructionComponent.generated.h"


UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class CPPCONTROL_API UDestructionComponent : public UActorComponent
{
	GENERATED_BODY()

public:
		UDestructionComponent();

protected:
	
	virtual void BeginPlay() override;

public:
	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	
	UFUNCTION(BlueprintCallable, Category = "Destruction")
	void DestructionBeam();

private:
	
	UPROPERTY(EditAnywhere, Category = "Destruction")
	float Range = 1000.0f;

	
	UPROPERTY(EditAnywhere, Category = "Destruction")
	UCameraComponent* Camera;
};

