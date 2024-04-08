// Copyright TazoGom Soft

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "GameplayEffectTypes.h"
#include "AuraAttributeSet.generated.h"

USTRUCT()
struct FEffectproperties
{
	GENERATED_BODY()

	UPROPERTY()
	TWeakObjectPtr<UAbilitySystemComponent> SourceASComp;
	UPROPERTY()
	TWeakObjectPtr<AActor>		SourceAvatarActor;
	UPROPERTY()
	TWeakObjectPtr<AController> SourceController;
	UPROPERTY()
	TWeakObjectPtr<ACharacter> SourceCharacter;

	UPROPERTY()
	TWeakObjectPtr<UAbilitySystemComponent> TargetASComp;
	UPROPERTY()
	TWeakObjectPtr<AActor>		TargetAvatarActor;
	UPROPERTY()
	TWeakObjectPtr<AController> TargetController;
	UPROPERTY()
	TWeakObjectPtr<ACharacter> TargetCharacter;

	UPROPERTY()
	FGameplayEffectContextHandle EffectContextHandle;
};

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

/**
 * 
 */
UCLASS()
class AURA_API UAuraAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

public:
	UAuraAttributeSet();
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;
	
public:
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing="OnRep_Helath", Category="Attributes|Vital")
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, Health);
	
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing="OnRep_MaxHelath", Category="Attributes|Vital")
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, MaxHealth);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing="OnRep_Mana", Category="Attributes|Vital")
	FGameplayAttributeData Mana;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, Mana);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing="OnRep_MaxMana", Category="Attributes|Vital")
	FGameplayAttributeData MaxMana;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, MaxMana);

	UFUNCTION()
	void OnRep_Helath(const FGameplayAttributeData& OldHealth) const;

	UFUNCTION()
	void OnRep_MaxHelath(const FGameplayAttributeData& OldMaxHealth) const;

	UFUNCTION()
	void OnRep_Mana(const FGameplayAttributeData& OldMana) const;

	UFUNCTION()
	void OnRep_MaxMana(const FGameplayAttributeData& OldMaxMana) const;
};
