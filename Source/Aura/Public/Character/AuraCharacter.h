// Copyright TazoGom Soft

#pragma once

#include "CoreMinimal.h"
#include "Character/AuraCharacterBase.h"
#include "AuraCharacter.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API AAuraCharacter : public AAuraCharacterBase
{
	GENERATED_BODY()

public:
	AAuraCharacter(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());
	void BeginPlay() override;
	void OnRep_PlayerState() override;

protected:
	void InitAbilityActorInfo();
};
