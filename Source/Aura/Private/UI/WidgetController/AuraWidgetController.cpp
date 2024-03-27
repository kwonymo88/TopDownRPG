// Copyright TazoGom Soft


#include "UI/WidgetController/AuraWidgetController.h"

void UAuraWidgetController::InitWidgetController(const FWidgetControllerParams& Param)
{
	PlayerController = Param.PlayerController;
	PlayerState = Param.PlayerState;
	AttributeSet = Param.AttributeSet;
	AbilitySystemComponent = Param.AbilitySystemComponent;
}
