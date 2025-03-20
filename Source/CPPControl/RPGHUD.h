#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "BarWidget.h"  
#include "RPGHUD.generated.h"

UCLASS()
class CPPCONTROL_API ARPGHUD : public AHUD
{
    GENERATED_BODY()

protected:
    virtual void BeginPlay() override;

private:
    UPROPERTY()
    UBarWidget* BarWidgetInstance;

    UPROPERTY(EditAnywhere, Category = "HUD")
    TSubclassOf<UBarWidget> BarWidgetClass;

public:
    UFUNCTION(BlueprintCallable)
    void SetPercent(const float& Percent);
};

