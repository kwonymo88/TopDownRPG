// Copyright TazoGom Soft

#pragma once

#include "CoreMinimal.h"
#include "UI/WidgetController/AuraWidgetController.h"
#include "AuraAttributeMenuWC.generated.h"

class UAttributeInfo;
struct FAuraAttributeInfo;
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAttributeInfoSignature, const FAuraAttributeInfo&, AttributeInfo);
/**
 * 
 */
UCLASS(BlueprintType, Blueprintable)
class AURA_API UAuraAttributeMenuWC : public UAuraWidgetController
{
	GENERATED_BODY()
	
public:
	UPROPERTY(BlueprintAssignable, Category="GAS|AttributeInfo");
	FOnAttributeInfoSignature OnAttributeInfoDelegate;

	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UAttributeInfo> AttributeInfoDataAsset;

public:
	UFUNCTION(BlueprintCallable)
	virtual void BroadcastInitValue() override;
	UFUNCTION(BlueprintCallable)
	virtual void BindCallbacksToDependencies() override;

};
