#include "BarWidget.h"
#include "Components/ProgressBar.h"

void UBarWidget::NativeConstruct()
{
    Super::NativeConstruct();

    
    if (!ProgressBar)
    {
        UE_LOG(LogTemp, Warning, TEXT("ProgressBar is not bound!"));
    }
}

void UBarWidget::SetPercent(const float& Percent)
{
    if (ProgressBar)
    {
       
        ProgressBar->SetPercent(FMath::Clamp(Percent, 0.0f, 1.0f));

        
        if (ColorGradient)
        {
            FLinearColor NewColor = ColorGradient->GetLinearColorValue(Percent);
            ProgressBar->SetFillColorAndOpacity(NewColor);
        }
    }
}

