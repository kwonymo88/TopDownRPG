// Copyright TazoGom Soft


#include "AbilitySystem/AuraAbilitySystemComponent.h"

void UAuraAbilitySystemComponent::InitAbilitySystemInfo()
{
	if (!OnGameplayEffectAppliedDelegateToSelf.IsBoundToObject(this))
	{
		OnGameplayEffectAppliedDelegateToSelf.AddUObject(this, &UAuraAbilitySystemComponent::AppliedEffect);	
	}
}

void UAuraAbilitySystemComponent::InitAbilityActorInfo(AActor* InOwnerActor, AActor* InAvatarActor)
{
	Super::InitAbilityActorInfo(InOwnerActor, InAvatarActor);
}

void UAuraAbilitySystemComponent::AppliedEffect(UAbilitySystemComponent* ASComp, const FGameplayEffectSpec& EffectSpec,
                                                FActiveGameplayEffectHandle EffectHandle)
{
	FGameplayTagContainer TagContainer;
	EffectSpec.GetAllAssetTags(TagContainer);
	EffectAssetTags.Broadcast(TagContainer);
}
