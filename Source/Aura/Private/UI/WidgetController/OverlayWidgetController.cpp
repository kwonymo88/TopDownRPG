// Copyright TazoGom Soft


#include "UI/WidgetController/OverlayWidgetController.h"

#include "AbilitySystem/AuraAbilitySystemComponent.h"
#include "AbilitySystem/AuraAttributeSet.h"

void UOverlayWidgetController::BroadcastInitValue()
{
	check(AttributeSet);
	OnChangedHealth.Broadcast(AttributeSet->GetHealth());
	OnChangedMaxHealth.Broadcast(AttributeSet->GetMaxHealth());
	OnChangedMana.Broadcast(AttributeSet->GetMana());
	OnChangedMaxMana.Broadcast(AttributeSet->GetMaxMana());
}

void UOverlayWidgetController::BindCallbacksToDependencies()
{
	Super::BindCallbacksToDependencies();
	
	FOnGameplayAttributeValueChange& HealthAttributeChangedValue = AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AttributeSet->GetHealthAttribute());
	HealthAttributeChangedValue.AddLambda([this](const FOnAttributeChangeData& newData)
		{
			OnChangedHealth.Broadcast(newData.NewValue);
		});
	
	FOnGameplayAttributeValueChange& MaxHealthAttributeChagne = AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AttributeSet->GetMaxHealthAttribute());
	MaxHealthAttributeChagne.AddLambda([this](const FOnAttributeChangeData& newData)
		{
			OnChangedMaxHealth.Broadcast(newData.NewValue);
		});
	
	FOnGameplayAttributeValueChange& ManaAttributeChangedValue = AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AttributeSet->GetManaAttribute());
	ManaAttributeChangedValue.AddLambda([this](const FOnAttributeChangeData& newData)
		{
			OnChangedMana.Broadcast(newData.NewValue);
		});
	
	FOnGameplayAttributeValueChange& MaxManaAttributeChagne = AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AttributeSet->GetMaxManaAttribute());
	MaxManaAttributeChagne.AddLambda([this](const FOnAttributeChangeData& newData)
		{
			OnChangedMaxMana.Broadcast(newData.NewValue);
		});

	Cast<UAuraAbilitySystemComponent>(AbilitySystemComponent)->EffectAssetTags.AddLambda([this](const FGameplayTagContainer& TagContainer)
	{
		for (const FGameplayTag& Tag : TagContainer)
		{
			if (Tag.MatchesTag(FGameplayTag::RequestGameplayTag(TEXT("Message"))))
			{
				const FString Msg = FString::Printf(TEXT("TagName : %s"), *Tag.ToString());
				GEngine->AddOnScreenDebugMessage(-1, 4.f, FColor::Green, Msg);

				if (MessageWidgetDataTable)
				{
					if (const FUIWidgetRow* UiWidgetRow = GetUIEffectTableRow<FUIWidgetRow>(MessageWidgetDataTable, Tag))
					{
						OnMessageWidgetDelegate.Broadcast(*UiWidgetRow);
					}	
				}
			}
			
		}
	});
}
