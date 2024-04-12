// Copyright TazoGom Soft


#include "AbilitySystem/MMC/MMC_MaxMana.h"

#include "AbilitySystem/AuraAttributeSet.h"
#include "Interaction/CombatInterface.h"

UMMC_MaxMana::UMMC_MaxMana()
{
	IntDef.AttributeSource = EGameplayEffectAttributeCaptureSource::Target;
	IntDef.AttributeToCapture = UAuraAttributeSet::GetIntelligenceAttribute();
	IntDef.bSnapshot = false;

	RelevantAttributesToCapture.Emplace(IntDef);
}

float UMMC_MaxMana::CalculateBaseMagnitude_Implementation(const FGameplayEffectSpec& Spec) const
{
	FAggregatorEvaluateParameters EvaluateParam;
	EvaluateParam.SourceTags = Spec.CapturedSourceTags.GetAggregatedTags();
	EvaluateParam.TargetTags = Spec.CapturedTargetTags.GetAggregatedTags();

	float IntMagnitude;
	GetCapturedAttributeMagnitude(IntDef, Spec, EvaluateParam, IntMagnitude);

	int32 PlayerLevel = 0;
	if (const ICombatInterface* CombatInterface = Cast<ICombatInterface>(Spec.GetContext().GetSourceObject()))
	{
		PlayerLevel = CombatInterface->GetPlayerLevel();
	}
	return 50.f + IntMagnitude * 3.f + PlayerLevel * 7.f;
}
