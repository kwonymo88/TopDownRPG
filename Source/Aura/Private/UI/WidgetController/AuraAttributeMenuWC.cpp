// Copyright TazoGom Soft


#include "UI/WidgetController/AuraAttributeMenuWC.h"

#include "AbilitySystem/AuraAttributeSet.h"
#include "AbilitySystem/AttributeInfo.h"
#include "AuraGameplayTags.h"

void UAuraAttributeMenuWC::BroadcastInitValue()
{
	for (const auto& pair : AttributeSet->AttributesMap)
	{
		FAuraAttributeInfo	AttributeInfo = AttributeInfoDataAsset->FindAttributeInfoForTag(pair.Key);
		AttributeInfo.AttributeValue = pair.Value().GetNumericValue(AttributeSet);
		OnAttributeInfoDelegate.Broadcast(AttributeInfo);
	}
}

void UAuraAttributeMenuWC::BindCallbacksToDependencies()
{
	for (const auto& pair : AttributeSet->AttributesMap)
	{
		FOnGameplayAttributeValueChange	GameplayAttValueChnage = AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(pair.Value());
		GameplayAttValueChnage.AddLambda([this, pair](const FOnAttributeChangeData& ChangeData) {
			FAuraAttributeInfo	AttributeInfo = AttributeInfoDataAsset->FindAttributeInfoForTag(pair.Key);
			AttributeInfo.AttributeValue = pair.Value().GetNumericValue(AttributeSet);
			OnAttributeInfoDelegate.Broadcast(AttributeInfo);
			});
	}
	
}
