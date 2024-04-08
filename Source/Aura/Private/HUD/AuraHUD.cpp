// Copyright TazoGom Soft


#include "HUD/AuraHUD.h"

#include "UI/Widget/AuraUserWidget.h"
#include "UI/WidgetController/OverlayWidgetController.h"

void AAuraHUD::BeginPlay()
{
	Super::BeginPlay();

	
}

void AAuraHUD::InitOverlay(APlayerController* PC, APlayerState* PS, UAuraAttributeSet* AS, UAbilitySystemComponent* ASC)
{
	checkf(OverlayWidgetControllerClass, TEXT("Need fill out OverlayWidgetControllerClass in BP_AuraHUD"));
	checkf(OverlayWidgetClass, TEXT("Need fill out OverlayWidgetClass in BP_AuraHUD"));

	UOverlayWidgetController* NewOverlayWidgetController = GetOverlayWidgetController(FWidgetControllerParams(PC, PS, AS, ASC));
	OverlayWidget = CreateWidget<UAuraUserWidget>(GetWorld(), OverlayWidgetClass);
	OverlayWidget->SetWidgetController(NewOverlayWidgetController);
	NewOverlayWidgetController->BroadcastInitValue();
	
	OverlayWidget->AddToViewport();
}

UOverlayWidgetController* AAuraHUD::GetOverlayWidgetController(const FWidgetControllerParams& Param)
{
	if (OverlayWidgetController == nullptr)
	{
		OverlayWidgetController = NewObject<UOverlayWidgetController>(this, OverlayWidgetControllerClass);
		OverlayWidgetController->InitWidgetController(Param);
		OverlayWidgetController->BindCallbacksToDependencies();
	}
	return OverlayWidgetController; 
}

