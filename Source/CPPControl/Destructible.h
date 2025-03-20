#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Destructible.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI, NotBlueprintable)
class UDestructible : public UInterface
{
    GENERATED_BODY()
};

class CPPCONTROL_API IDestructible
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, Category = "Destructible")
    virtual void DestroyObject() = 0;
};
