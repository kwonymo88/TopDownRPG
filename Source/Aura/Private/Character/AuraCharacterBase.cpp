// Copyright TazoGom Soft


#include "Character/AuraCharacterBase.h"

#include "AbilitySystemComponent.h"
#include "GameplayEffect.h"

// AAuraCharacterBase::AAuraCharacterBase()
// {
//  	
// }

AAuraCharacterBase::AAuraCharacterBase(const FObjectInitializer& ObjectInitializer)
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>("Weapon");
	Weapon->SetupAttachment(GetMesh(), FName("WeaponHandSocket"));
	Weapon->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

void AAuraCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

void AAuraCharacterBase::InitAbilityActorInfo()
{
	
}

void AAuraCharacterBase::ApplySpecToSelf(const TSubclassOf<UGameplayEffect>& ApplyGameplayEffect, float Level) const
{
	check(GetAbilitySystemComponent());
	check(ApplyGameplayEffect);

	const FGameplayEffectContextHandle EffectContextHandle = GetAbilitySystemComponent()->MakeEffectContext();
	const FGameplayEffectSpecHandle GameplayEffectSpecHandle = GetAbilitySystemComponent()->MakeOutgoingSpec(ApplyGameplayEffect, Level, EffectContextHandle);
	GetAbilitySystemComponent()->ApplyGameplayEffectSpecToTarget(*GameplayEffectSpecHandle.Data.Get(), GetAbilitySystemComponent());
}

void AAuraCharacterBase::InitDefaultAttributes() const
{
	ApplySpecToSelf(DefaultPrimaryAttributes);
	ApplySpecToSelf(DefaultSecondaryAttributes);
}

UAbilitySystemComponent* AAuraCharacterBase::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

