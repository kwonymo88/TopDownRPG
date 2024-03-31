// Copyright TazoGom Soft


#include "Actor/AuraEffectActor.h"

#include "AbilitySystemComponent.h"
#include "AbilitySystemBlueprintLibrary.h"

// Sets default values
AAuraEffectActor::AAuraEffectActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	SetRootComponent(CreateDefaultSubobject<USceneComponent>("RootSceneComponent"));
}

void AAuraEffectActor::ApplyEffectToTarget(AActor* TargetActor, TSubclassOf<UGameplayEffect> GameplayEffectClass,
	EEffectRemovalPolicy RemovalPolicy)
{
	UAbilitySystemComponent* ASCComp = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(TargetActor);
	if (ASCComp == nullptr) return;

	check(GameplayEffectClass);
	if (GameplayEffectClass == nullptr) return;

	FGameplayEffectContextHandle EffectContextHandle = ASCComp->MakeEffectContext();
	EffectContextHandle.AddSourceObject(this);
	const FGameplayEffectSpecHandle EffectSpecHandle = ASCComp->MakeOutgoingSpec(GameplayEffectClass, 1.f, EffectContextHandle);
	const FActiveGameplayEffectHandle ActivateEffectHandle = ASCComp->ApplyGameplayEffectSpecToSelf(*EffectSpecHandle.Data.Get());

	if (RemovalPolicy == EEffectRemovalPolicy::EEndOverlap)
	{
		ActivateEffectForRemoveList.Add(FActivateEffectData(RemovalPolicy, ASCComp, ActivateEffectHandle));
	}
}

void AAuraEffectActor::OnBeginOverlap(AActor* TargetActor)
{
	for(const auto& ApplicationData : EffectApplicationDatas)
	{
		if (ApplicationData.AppliciatonPolicy == EEffectAppliciatonPolicy::EBeginOverlap)
		{
			ApplyEffectToTarget(TargetActor, ApplicationData.EffectClass, ApplicationData.RemovalPolicy);
		}
	}
}

void AAuraEffectActor::OnEndOverlap(AActor* TargetActor)
{
	for(const auto& ApplicationData : EffectApplicationDatas)
	{
		if (ApplicationData.AppliciatonPolicy == EEffectAppliciatonPolicy::EEndOverlap)
		{
			ApplyEffectToTarget(TargetActor, ApplicationData.EffectClass, ApplicationData.RemovalPolicy);
		}
	}

	UAbilitySystemComponent* ASComp = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(TargetActor);
	if (ASComp == nullptr ) return;

	TArray<FActivateEffectData> HandlesToRemove;
	for(const auto& ApplicationData : EffectApplicationDatas)
	{
		for(const auto& ActivateEffect : ActivateEffectForRemoveList)
		{
			if (ActivateEffect.RemovalPolicy == ApplicationData.RemovalPolicy
				&& ASComp == ActivateEffect.AbilitySystemComponent)
			{
				HandlesToRemove.Add(ActivateEffect);
			}
		}

		for (const auto& EffectHandle : HandlesToRemove)
		{
			ASComp->RemoveActiveGameplayEffect(EffectHandle.ActivateEffectHandle, 1);
			ActivateEffectForRemoveList.RemoveAll([EffectHandle](const FActivateEffectData& Data)
			{
				if (EffectHandle.ActivateEffectHandle == Data.ActivateEffectHandle
					&& EffectHandle.RemovalPolicy == Data.RemovalPolicy)
				{
					return true;
				}
				return false;
			});
		}
		
		
	}
}


