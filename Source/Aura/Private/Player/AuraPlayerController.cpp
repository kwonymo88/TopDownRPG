// Copyright TazoGom Soft


#include "Player/AuraPlayerController.h"

#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "GameFramework/Character.h"
#include "Interaction/EnemyInterface.h"

AAuraPlayerController::AAuraPlayerController()
{
	bReplicates = true;
}

void AAuraPlayerController::BeginPlay()
{
	Super::BeginPlay();
	check(AuraContext);

	if (UEnhancedInputLocalPlayerSubsystem* SubInputSystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		SubInputSystem->AddMappingContext(AuraContext, 0);	
	}

	FInputModeGameAndUI InputModeData;
	InputModeData.SetHideCursorDuringCapture(false);
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	SetInputMode(InputModeData);

	SetShowMouseCursor(true);
	
}

void AAuraPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);
	EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AAuraPlayerController::Move);
}

void AAuraPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);

	UpdateCursor();
}

void AAuraPlayerController::UpdateCursor()
{
	FHitResult HitResult;
	GetHitResultUnderCursor(ECC_Visibility, false, HitResult);
	if (HitResult.bBlockingHit == false)
		return;

	/*
	 * 커서 아래 오브젝트 체크 로직 시나리오 
	 * 1. LastHitEnemyInterface is null, ThisHittedEnemyInterface is null
	 *  - 아무것도 안 한다
	 * 2. LastHitEnemyInterface is null, ThisHittedEnemyInterface is not null
	 *  - Highlight Actor
	 * 3. LastHitEnemyInterface is not null, ThisHittedEnemyInterface is null
	 *  - UnHighlight Actor
	 * 4. LastHitEnemyInterface is not null, ThisHittedEnemyInterface is not null
	 *  4.1 LastHitEnemyInterface == ThisHittedEnemyInterface
	 *   - 같은 오브젝트이기 때문에 무시
	 *  4.1 LastHitEnemyInterface != ThisHittedEnemyInterface
	 *   - LastHitEnemyInterface UnHighlight
	 *   - ThisHittedEnemyInterface Highlight
	 */


	IEnemyInterface* ThisHittedEnemyInterface = Cast<IEnemyInterface>(HitResult.GetActor());
	
	if (ThisHittedEnemyInterface == nullptr)
	{
		if (LastHitEnemyInterface == nullptr)
		{
			//Case 1
		}
		else
		{
			//Case 3
			LastHitEnemyInterface->UnHighlightActor();
		}
	}
	else
	{
		if (LastHitEnemyInterface)
		{
			if (LastHitEnemyInterface == ThisHittedEnemyInterface)
			{
				//Case 4-1
			}
			else
			{
				//Case 4-2
				LastHitEnemyInterface->UnHighlightActor();
				ThisHittedEnemyInterface->HighlightActor();
			}
		}
		else
		{
			//Case 2
			ThisHittedEnemyInterface->HighlightActor();
		}
	}

	LastHitEnemyInterface = ThisHittedEnemyInterface;
}

void AAuraPlayerController::Move(const FInputActionValue& InputActionValue)
{
	const FVector2D InputAxisVector = InputActionValue.Get<FVector2D>();
	const FRotator Rotation = GetControlRotation();
	const FRotator YawRotation(0.f, Rotation.Yaw, 0.f);

	if (ACharacter* pPlayerPawn = GetPawn<ACharacter>())
	{
		const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		pPlayerPawn->AddMovementInput(ForwardDirection, InputAxisVector.Y);
		pPlayerPawn->AddMovementInput(RightDirection, InputAxisVector.X);
	}
}


