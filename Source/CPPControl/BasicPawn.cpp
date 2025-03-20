#include "BasicPawn.h"
#include "Components/StaticMeshComponent.h"
#include "Camera/CameraComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputAction.h"
#include "InputMappingContext.h"


ABasicPawn::ABasicPawn()
{
    PrimaryActorTick.bCanEverTick = true;

    
    Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
    RootComponent = Root;

    
    CubeMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CubeMesh"));
    CubeMesh->SetupAttachment(Root);

    static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeMeshAsset(TEXT("/Engine/BasicShapes/Cube"));
    if (CubeMeshAsset.Succeeded())
    {
        CubeMesh->SetStaticMesh(CubeMeshAsset.Object);
    }

 
    Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
    Camera->SetupAttachment(Root);
    Camera->SetRelativeLocation(FVector(-200.f, 0.f, 100.f));
    Camera->SetRelativeRotation(FRotator(-10.f, 0.f, 0.f));

  
    MoveSpeed = 600.f;
    RotationSpeed = 100.f;
    MoveSmoothness = 5.f;
    RotationSmoothness = 5.f;

    TargetForwardSpeed = 0.f;
    CurrentForwardSpeed = 0.f;
    TargetRotationSpeed = 0.f;
    CurrentRotationSpeed = 0.f;
}


void ABasicPawn::BeginPlay()
{
    Super::BeginPlay();

    
    if (APlayerController* PlayerController = Cast<APlayerController>(GetController()))
    {
        if (UEnhancedInputLocalPlayerSubsystem* InputSubsystem =
            ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
        {
            InputSubsystem->AddMappingContext(InputMappingContext, 0);
        }
    }
}


void ABasicPawn::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    CurrentForwardSpeed = FMath::FInterpTo(CurrentForwardSpeed, TargetForwardSpeed, DeltaTime, MoveSmoothness);
    CurrentRotationSpeed = FMath::FInterpTo(CurrentRotationSpeed, TargetRotationSpeed, DeltaTime, RotationSmoothness);

    FVector MoveDirection = GetActorForwardVector() * CurrentForwardSpeed * DeltaTime;
    AddActorWorldOffset(MoveDirection, true);

    FRotator NewRotation = GetActorRotation();
    NewRotation.Yaw += CurrentRotationSpeed * DeltaTime;
    SetActorRotation(NewRotation);
}

void ABasicPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);

    if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
    {
        // Avancer/Reculer
        EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ABasicPawn::Move);
        EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Completed, this, &ABasicPawn::StopMove);

        // Tourner
        EnhancedInputComponent->BindAction(TurnAction, ETriggerEvent::Triggered, this, &ABasicPawn::Turn);
        EnhancedInputComponent->BindAction(TurnAction, ETriggerEvent::Completed, this, &ABasicPawn::StopTurn);
    }
}


void ABasicPawn::Move(const FInputActionValue& Value)
{
    float MovementInput = Value.Get<float>();
    TargetForwardSpeed = MovementInput * MoveSpeed;
}

void ABasicPawn::Turn(const FInputActionValue& Value)
{
    float TurnInput = Value.Get<float>();
    TargetRotationSpeed = TurnInput * RotationSpeed;
}
void ABasicPawn::StopMove(const FInputActionValue& Value)
{
    TargetForwardSpeed = 0.f; 
}

void ABasicPawn::StopTurn(const FInputActionValue& Value)
{
    TargetRotationSpeed = 0.f; 
}

