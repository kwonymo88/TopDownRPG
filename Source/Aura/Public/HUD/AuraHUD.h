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
class UAuraAttributeMenuWC;

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
	UOverlayWidgetController* GetOverlayWidgetController(const FWidgetControllerParams& Param);
	UAuraAttributeMenuWC* GetAttributeMenuWidgetController(const FWidgetControllerParams& Param);

protected:	
	TObjectPtr<UAuraUserWidget> OverlayWidget;
	TObjectPtr<UOverlayWidgetController> OverlayWidgetController;
	TObjectPtr<UAuraAttributeMenuWC> AttributeMenuWidgetController;
	
private:
	UPROPERTY(EditAnywhere)
	TSubclassOf<UAuraUserWidget> OverlayWidgetClass;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UOverlayWidgetController> OverlayWidgetControllerClass;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UAuraAttributeMenuWC> AttributeMenuWidgetControllerClass;
};
