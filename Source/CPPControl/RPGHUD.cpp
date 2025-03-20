#include "RPGHUD.h"
#include "Blueprint/UserWidget.h"

void ARPGHUD::BeginPlay()
{
    Super::BeginPlay();

    if (BarWidgetClass)  
    {
        
        BarWidgetInstance = CreateWidget<UBarWidget>(GetWorld(), BarWidgetClass);
        if (BarWidgetInstance)
        {
            BarWidgetInstance->AddToViewport();  
        }
    }
}

void ARPGHUD::SetPercent(const float& Percent)
{
    if (BarWidgetInstance)
    {
        BarWidgetInstance->SetPercent(Percent); 
    }
}

