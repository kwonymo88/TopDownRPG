// Copyright TazoGom Soft

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "Interaction/CombatInterface.h"
#include "AuraCharacterBase.generated.h"

class UAuraAttributeSet;
class UAbilitySystemComponent;
class UGameplayEffect;

UCLASS(Abstract)
class AURA_API AAuraCharacterBase : public ACharacter, public IAbilitySystemInterface, public ICombatInterface
{
	GENERATED_BODY()

public:
	AAuraCharacterBase(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category="Combat")
	TObjectPtr<USkeletalMeshComponent> Weapon;

	UPROPERTY()
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY()
	TObjectPtr<UAuraAttributeSet> AuraAttributeSet;

protected:
	virtual void InitAbilityActorInfo();

	// Begin Default Attributes
protected:
	void ApplySpecToSelf(const TSubclassOf<UGameplayEffect>& ApplyGameplayEffect, float Level = 1.f) const;
	void InitDefaultAttributes() const;
protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Attributes|Default")
	TSubclassOf<UGameplayEffect> DefaultPrimaryAttributes;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Attributes|Default")
	TSubclassOf<UGameplayEffect> DefaultSecondaryAttributes;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Attributes|Default")
	TSubclassOf<UGameplayEffect> DefaultVitalAttributes;
	// End Default Attributes
	
public:
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	UAuraAttributeSet* GetAttributeSet() const { return AuraAttributeSet; }
	
};
