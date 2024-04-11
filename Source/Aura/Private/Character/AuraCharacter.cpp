// Copyright TazoGom Soft


#include "Character/AuraCharacter.h"

#include "AbilitySystemComponent.h"
#include "AbilitySystem/AuraAbilitySystemComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "HUD/AuraHUD.h"
#include "Player/AuraPlayerController.h"
#include "Player/AuraPlayerState.h"

AAuraCharacter::AAuraCharacter(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.f, 400.f, 0.f);

	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;

}

void AAuraCharacter::BeginPlay()
{
	Super::BeginPlay();

	InitAbilityActorInfo();
}

void AAuraCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();

	InitAbilityActorInfo();	
}

void AAuraCharacter::InitAbilityActorInfo()
{
	if (AAuraPlayerState* AuraPlayerState = Cast<AAuraPlayerState>(GetPlayerState()))
	{
		AbilitySystemComponent = AuraPlayerState->GetAbilitySystemComponent();
		AuraAttributeSet = AuraPlayerState->GetAttributeSet();
		check(AbilitySystemComponent);
		AbilitySystemComponent->InitAbilityActorInfo(AuraPlayerState, this);
		InitDefaultAttributes();
		Cast<UAuraAbilitySystemComponent>(AbilitySystemComponent)->InitAbilitySystemInfo();

		if (AAuraPlayerController* AuraPlayerController = GetController<AAuraPlayerController>())
		{
			if (AAuraHUD* AuraHUD = AuraPlayerController->GetHUD<AAuraHUD>())
			{
				AuraHUD->InitOverlay(AuraPlayerController, GetPlayerState(), AuraAttributeSet, AbilitySystemComponent);
			}	
		}
	}
}

int32 AAuraCharacter::GetPlayerLevel() const
{
	const AAuraPlayerState* AuraPlayerState = GetPlayerState<AAuraPlayerState>();
	check(AuraPlayerState);
	return AuraPlayerState->GetPlayerLevel();
}
