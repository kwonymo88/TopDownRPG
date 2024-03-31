// Copyright TazoGom Soft


#include "UI/WidgetController/OverlayWidgetController.h"

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
	HealthAttributeChangedValue.AddUObject(this, &UOverlayWidgetController::HealthChanged);
	
	FOnGameplayAttributeValueChange& MaxHealthAttributeChagne = AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AttributeSet->GetMaxHealthAttribute());
	MaxHealthAttributeChagne.AddUObject(this, &UOverlayWidgetController::MaxHealthChanged);

	FOnGameplayAttributeValueChange& ManaAttributeChangedValue = AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AttributeSet->GetManaAttribute());
	ManaAttributeChangedValue.AddUObject(this, &UOverlayWidgetController::ManaChanged);
	
	FOnGameplayAttributeValueChange& MaxManaAttributeChagne = AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AttributeSet->GetMaxManaAttribute());
	MaxManaAttributeChagne.AddUObject(this, &UOverlayWidgetController::MaxManaChanged);
}

void UOverlayWidgetController::HealthChanged(const FOnAttributeChangeData& newData) const
{
	OnChangedHealth.Broadcast(newData.NewValue);
}

void UOverlayWidgetController::MaxHealthChanged(const FOnAttributeChangeData& newData) const
{
	OnChangedMaxHealth.Broadcast(newData.NewValue);
}

void UOverlayWidgetController::ManaChanged(const FOnAttributeChangeData& newData) const
{
	OnChangedMana.Broadcast(newData.NewValue);
}

void UOverlayWidgetController::MaxManaChanged(const FOnAttributeChangeData& newData) const
{
	OnChangedMaxMana.Broadcast(newData.NewValue);
}
