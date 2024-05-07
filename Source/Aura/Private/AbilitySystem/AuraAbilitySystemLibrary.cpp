// Copyright TazoGom Soft


#include "AbilitySystem/AuraAbilitySystemLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "HUD/AuraHUD.h"
#include "UI/WidgetController/AuraWidgetController.h"
#include "Player/AuraPlayerState.h"

UOverlayWidgetController* UAuraAbilitySystemLibrary::GetOverlayWidgetController(const UObject* WorldContextObject)
{
	if (APlayerController* pPlayerController = UGameplayStatics::GetPlayerController(WorldContextObject, 0))
	{
		if (AAuraHUD* pAuraHUD = pPlayerController->GetHUD<AAuraHUD>())
		{
			AAuraPlayerState* pPlayerState = pPlayerController->GetPlayerState<AAuraPlayerState>();
			UAuraAttributeSet* pAttributeSet = pPlayerState->GetAttributeSet();
			return pAuraHUD->GetOverlayWidgetController(FWidgetControllerParams(pPlayerController, pPlayerState, pAttributeSet, pPlayerState->GetAbilitySystemComponent()));
		}
	}

	return nullptr;
}

UAuraAttributeMenuWC* UAuraAbilitySystemLibrary::GetAttributeMenuWidgetController(const UObject* WorldContextObject)
{
	if (APlayerController* pPlayerController = UGameplayStatics::GetPlayerController(WorldContextObject, 0))
	{
		if (AAuraHUD* pAuraHUD = pPlayerController->GetHUD<AAuraHUD>())
		{
			AAuraPlayerState* pPlayerState = pPlayerController->GetPlayerState<AAuraPlayerState>();
			UAuraAttributeSet* pAttributeSet = pPlayerState->GetAttributeSet();
			return pAuraHUD->GetAttributeMenuWidgetController(FWidgetControllerParams(pPlayerController, pPlayerState, pAttributeSet, pPlayerState->GetAbilitySystemComponent()));
		}
	}
	return nullptr;
}
