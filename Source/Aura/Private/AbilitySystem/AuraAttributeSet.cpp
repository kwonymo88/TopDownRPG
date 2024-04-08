// Copyright TazoGom Soft


#include "AbilitySystem/AuraAttributeSet.h"
#include "GameplayEffectExtension.h"
#include "GameFramework/Character.h"
#include "Net/UnrealNetwork.h"

UAuraAttributeSet::UAuraAttributeSet()
{
	InitHealth(50.f);
	InitMaxHealth(100.f);
	InitMana(0.f);
	InitMaxMana(50.f);
}

void UAuraAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION_NOTIFY(UAuraAttributeSet, Health, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UAuraAttributeSet, MaxHealth, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UAuraAttributeSet, Mana, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UAuraAttributeSet, MaxMana, COND_None, REPNOTIFY_Always);
}

void UAuraAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	Super::PreAttributeChange(Attribute, NewValue);

	if (Attribute == GetHealthAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 0.f, GetMaxHealth());
	}
	else if(Attribute == GetManaAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 0.f, GetMaxMana());
	}
}

void UAuraAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);

	
	FGameplayEffectContextHandle EffectContextHandle = Data.EffectSpec.GetContext();

	FEffectproperties NewEffectproperties;
	NewEffectproperties.EffectContextHandle = EffectContextHandle;
	NewEffectproperties.SourceASComp = EffectContextHandle.GetOriginalInstigatorAbilitySystemComponent();
	if (NewEffectproperties.SourceASComp.IsValid()
		&& NewEffectproperties.SourceASComp->AbilityActorInfo.IsValid())
	{
		NewEffectproperties.SourceAvatarActor = NewEffectproperties.SourceASComp->AbilityActorInfo.Get()->AvatarActor;
		NewEffectproperties.SourceController = NewEffectproperties.SourceASComp->AbilityActorInfo.Get()->PlayerController;
		if (NewEffectproperties.SourceController == nullptr
			&& NewEffectproperties.SourceAvatarActor.IsValid())
		{
			if (const APawn* pSourcePawn = Cast<APawn>(NewEffectproperties.SourceAvatarActor))
			{
				NewEffectproperties.SourceController = pSourcePawn->GetController();
			}
		}
		if (NewEffectproperties.SourceController.IsValid())
		{
			NewEffectproperties.SourceCharacter = NewEffectproperties.SourceController->GetPawn<ACharacter>();	
		}
	}
	NewEffectproperties.TargetASComp = &Data.Target;
	if (NewEffectproperties.TargetASComp.IsValid()
		&& NewEffectproperties.TargetASComp->AbilityActorInfo.IsValid())
	{
		NewEffectproperties.TargetAvatarActor = NewEffectproperties.TargetASComp->AbilityActorInfo.Get()->AvatarActor;
		NewEffectproperties.TargetController = NewEffectproperties.TargetASComp->AbilityActorInfo.Get()->PlayerController;
		NewEffectproperties.TargetCharacter = Cast<ACharacter>(NewEffectproperties.TargetAvatarActor); 
	}
}

void UAuraAttributeSet::OnRep_Helath(const FGameplayAttributeData& OldHealth) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAuraAttributeSet, Health, OldHealth);
}

void UAuraAttributeSet::OnRep_MaxHelath(const FGameplayAttributeData& OldMaxHealth) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAuraAttributeSet, MaxHealth, OldMaxHealth);
}

void UAuraAttributeSet::OnRep_Mana(const FGameplayAttributeData& OldMana) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAuraAttributeSet, Mana, OldMana);
}

void UAuraAttributeSet::OnRep_MaxMana(const FGameplayAttributeData& OldMaxMana) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAuraAttributeSet, MaxMana, OldMaxMana);
}
