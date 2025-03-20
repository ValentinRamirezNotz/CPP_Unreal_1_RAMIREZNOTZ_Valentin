#include "DestructionComponent.h"
#include "Engine/World.h"
#include "DrawDebugHelpers.h" 
#include "Destructible.h"  

UDestructionComponent::UDestructionComponent()
{
	PrimaryComponentTick.bCanEverTick = true;  
}


void UDestructionComponent::BeginPlay()
{
	Super::BeginPlay();

	
	if (AActor* Owner = GetOwner())
	{
		Camera = Owner->FindComponentByClass<UCameraComponent>();
	}
}

void UDestructionComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	
}


void UDestructionComponent::DestructionBeam()
{
	
	if (!Camera)
	{
		UE_LOG(LogTemp, Warning, TEXT("La caméra n'est pas définie !"));
		return;
	}

	
	FVector Start = Camera->GetComponentLocation();  
	FVector ForwardVector = Camera->GetForwardVector();  
	FVector End = Start + (ForwardVector * Range); 

	
	FHitResult HitResult;

	
	FCollisionQueryParams CollisionParams;

	
	bool bHit = GetWorld()->LineTraceSingleByChannel(HitResult, Start, End, ECC_Visibility, CollisionParams);


#if WITH_EDITOR
	if (bHit)
	{
		DrawDebugLine(GetWorld(), Start, End, FColor::Red, false, 1.0f, 0, 1.0f);
	}
#endif

	if (bHit && HitResult.GetActor())
	{
		if (IDestructible* DestructibleActor = Cast<IDestructible>(HitResult.GetActor()))
		{
			DestructibleActor->DestroyObject();  
		}
	}
}
