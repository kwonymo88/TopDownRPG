// Copyright TazoGom Soft


#include "Character/AuraEnemyCharacter.h"

#include "Aura/Aura.h"

AAuraEnemyCharacter::AAuraEnemyCharacter(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	GetMesh()->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);
}

void AAuraEnemyCharacter::HighlightActor()
{
	bHighlighttActor = true;

	GetMesh()->SetRenderCustomDepth(true);
	GetMesh()->SetCustomDepthStencilValue(kHighlight_Stencil_Value);
	if (Weapon)
	{
		Weapon->SetRenderCustomDepth(true);
		Weapon->SetCustomDepthStencilValue(kHighlight_Stencil_Value);
	}
}

void AAuraEnemyCharacter::UnHighlightActor()
{
	bHighlighttActor = false;
	GetMesh()->SetRenderCustomDepth(false);
	if (Weapon)
    {
    	Weapon->SetRenderCustomDepth(false);
    }
}
