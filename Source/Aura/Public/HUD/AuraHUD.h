// Copyright TazoGom Soft

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "AuraHUD.generated.h"

struct FWidgetControllerParams;
class UAbilitySystemComponent;
class UAuraAttributeSet;
class UOverlayWidgetController;
class UAuraUserWidget;
/**
 * 
 */
UCLASS()
class AURA_API AAuraHUD : public AHUD
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

public:
	void InitOverlay(APlayerController* PC, APlayerState* PS, UAuraAttributeSet* AS, UAbilitySystemComponent* ASC);
	
protected:
	UOverlayWidgetController* GetOverlayWidgetController(const FWidgetControllerParams& Param);
	TObjectPtr<UAuraUserWidget> OverlayWidget;
	TObjectPtr<UOverlayWidgetController> OverlayWidgetController;
	
private:
	UPROPERTY(EditAnywhere)
	TSubclassOf<UAuraUserWidget> OverlayWidgetClass;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UOverlayWidgetController> OverlayWidgetControllerClass;
	
	
};
