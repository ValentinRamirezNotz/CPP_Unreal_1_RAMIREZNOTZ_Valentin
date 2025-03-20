#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "InputActionValue.h"  
#include "BasicPawn.generated.h"

class UInputMappingContext;
class UInputAction;

UCLASS()
class CPPCONTROL_API ABasicPawn : public APawn
{
    GENERATED_BODY()

public:
    ABasicPawn();

protected:
    virtual void BeginPlay() override;
    virtual void Tick(float DeltaTime) override;
    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
    
    UPROPERTY(VisibleAnywhere)
    class USceneComponent* Root;

    UPROPERTY(VisibleAnywhere)
    class UStaticMeshComponent* CubeMesh;

    UPROPERTY(VisibleAnywhere)
    class UCameraComponent* Camera;

    
    UPROPERTY(EditAnywhere, Category = "Movement")
    float MoveSpeed;

    UPROPERTY(EditAnywhere, Category = "Movement")
    float RotationSpeed;

    UPROPERTY(EditAnywhere, Category = "Smooth")
    float MoveSmoothness;

    UPROPERTY(EditAnywhere, Category = "Smooth")
    float RotationSmoothness;

   
    float TargetForwardSpeed;
    float CurrentForwardSpeed;

    float TargetRotationSpeed;
    float CurrentRotationSpeed;

    
    UPROPERTY(EditAnywhere, Category = "Input")
    UInputMappingContext* InputMappingContext;

    UPROPERTY(EditAnywhere, Category = "Input")
    UInputAction* MoveAction;

    UPROPERTY(EditAnywhere, Category = "Input")
    UInputAction* TurnAction;

    
    void Move(const FInputActionValue& Value);
    void Turn(const FInputActionValue& Value);
    void StopMove(const FInputActionValue& Value);
    void StopTurn(const FInputActionValue& Value);
};