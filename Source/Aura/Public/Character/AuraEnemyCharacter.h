// Copyright TazoGom Soft

#pragma once

#include "CoreMinimal.h"
#include "Character/AuraCharacterBase.h"
#include "Interaction/EnemyInterface.h"
#include "AuraEnemyCharacter.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API AAuraEnemyCharacter : public AAuraCharacterBase, public IEnemyInterface
{
	GENERATED_BODY()

protected:
	AAuraEnemyCharacter(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());
	
public:
	virtual void HighlightActor() override;
	virtual void UnHighlightActor() override;

protected:
	UPROPERTY(BlueprintReadOnly, Category="EnemyInterface")
	bool bHighlighttActor;
};
