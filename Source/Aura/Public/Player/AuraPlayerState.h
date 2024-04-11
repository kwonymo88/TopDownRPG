// Copyright TazoGom Soft

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/PlayerState.h"
#include "AuraPlayerState.generated.h"

class UAuraAttributeSet;
class UAbilitySystemComponent;

/**
 * 
 */
UCLASS()
class AURA_API AAuraPlayerState : public APlayerState, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	AAuraPlayerState();
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

protected:
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY()
	TObjectPtr<UAuraAttributeSet> AuraAttributeSet;

public:
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	UAuraAttributeSet* GetAttributeSet() const { return AuraAttributeSet; }

protected:
	UPROPERTY(VisibleAnywhere, ReplicatedUsing="OnRep_PlayerLevel")
	int32 PlayerLevel;

	UFUNCTION()
	void OnRep_PlayerLevel(int32 OldPlayerLevel);

public:
	FORCEINLINE int32 GetPlayerLevel() const { return PlayerLevel;}
};
