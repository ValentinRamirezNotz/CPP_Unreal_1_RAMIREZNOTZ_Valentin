#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/ProgressBar.h"
#include "Curves/CurveLinearColor.h"
#include "BarWidget.generated.h"

UCLASS()
class CPPCONTROL_API UBarWidget : public UUserWidget
{
    GENERATED_BODY()

protected:
    virtual void NativeConstruct() override;

public:
    
    UFUNCTION(BlueprintCallable, Category = "UI")
    void SetPercent(const float& Percent);

private:
    
    UPROPERTY(meta = (BindWidget))
    UProgressBar* ProgressBar;

   
    UPROPERTY(EditAnywhere, Category = "UI")
    UCurveLinearColor* ColorGradient;
};
