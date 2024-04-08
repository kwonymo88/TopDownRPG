// Copyright TazoGom Soft

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "AuraAbilitySystemComponent.generated.h"

DECLARE_MULTICAST_DELEGATE_OneParam(FEffectAssetTags, const FGameplayTagContainer& /*TagContainer*/);

/**
 * 
 */
UCLASS()
class AURA_API UAuraAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()
public:
	void InitAbilitySystemInfo();
	virtual void InitAbilityActorInfo(AActor* InOwnerActor, AActor* InAvatarActor) override;

public:
	FEffectAssetTags EffectAssetTags;
	
protected:
	void AppliedEffect(UAbilitySystemComponent* ASComp, const FGameplayEffectSpec& EffectSpec, FActiveGameplayEffectHandle EffectHandle);
};
