// Copyright TazoGom Soft

#pragma once

#include "CoreMinimal.h"
#include "UI/WidgetController/AuraWidgetController.h"
#include "OverlayWidgetController.generated.h"

struct FOnAttributeChangeData;
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnChangedHealthSignature, float, NewHealth);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnChangedMaxHealthSignature, float, NewMaxHealth);
/**
 * 
 */
UCLASS(BlueprintType, Blueprintable)
class AURA_API UOverlayWidgetController : public UAuraWidgetController
{
	GENERATED_BODY()

public:
	virtual void BroadcastInitValue() override;
	virtual void BindCallbacksToDependencies() override;

	UPROPERTY(BlueprintAssignable, Category="GAS|Attributes")
	FOnChangedHealthSignature OnChangedHealth;

	UPROPERTY(BlueprintAssignable, Category="GAS|Attributes")
	FOnChangedMaxHealthSignature OnChangedMaxHealth;

	UPROPERTY(BlueprintAssignable, Category="GAS|Attributes")
	FOnChangedHealthSignature OnChangedMana;

	UPROPERTY(BlueprintAssignable, Category="GAS|Attributes")
	FOnChangedMaxHealthSignature OnChangedMaxMana;

protected:
	void HealthChanged(const FOnAttributeChangeData& newData) const;
	void MaxHealthChanged(const FOnAttributeChangeData& newData) const;
	void ManaChanged(const FOnAttributeChangeData& newData) const;
	void MaxManaChanged(const FOnAttributeChangeData& newData) const;
};
