// Copyright TazoGom Soft

#pragma once

#include "CoreMinimal.h"
#include "ActiveGameplayEffectHandle.h"
#include "GameFramework/Actor.h"
#include "AuraEffectActor.generated.h"

class UGameplayEffect;

UENUM(BlueprintType)
enum class EEffectAppliciatonPolicy
{
	EBeginOverlap,
	EEndOverlap,
	ENone,
};

UENUM(BlueprintType)
enum class EEffectRemovalPolicy
{
	EEndOverlap,
	ENone,
};

USTRUCT(BlueprintType)
struct FEffectApplicationData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSubclassOf<UGameplayEffect> EffectClass;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	EEffectAppliciatonPolicy AppliciatonPolicy = EEffectAppliciatonPolicy::EBeginOverlap;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	EEffectRemovalPolicy RemovalPolicy = EEffectRemovalPolicy::ENone;
};

USTRUCT(BlueprintType)
struct FActivateEffectData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	EEffectRemovalPolicy RemovalPolicy;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FActiveGameplayEffectHandle ActivateEffectHandle;
};

UCLASS()
class AURA_API AAuraEffectActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAuraEffectActor();

public:
	UFUNCTION(BlueprintCallable)
	void ApplyEffectToTarget(AActor* TargetActor, TSubclassOf<UGameplayEffect> GameplayEffectClass, EEffectRemovalPolicy RemovalPolicy = EEffectRemovalPolicy::ENone);

	UFUNCTION(BlueprintCallable)
	void OnBeginOverlap(AActor* TargetActor);
	
	UFUNCTION(BlueprintCallable)
	void OnEndOverlap(AActor* TargetActor);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Applied Effects")
	TArray<FEffectApplicationData> EffectApplicationDatas;

	UPROPERTY(Transient, BlueprintReadOnly, Category = "Applied Effects")
	TArray<FActivateEffectData> ActivateEffectForRemoveList;
};
