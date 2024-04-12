// Copyright TazoGom Soft


#include "AbilitySystem/MMC/MMC_MaxHealth.h"

#include "AbilitySystem/AuraAttributeSet.h"
#include "Interaction/CombatInterface.h"

UMMC_MaxHealth::UMMC_MaxHealth()
{
	VigorDef.bSnapshot = false;
	VigorDef.AttributeToCapture = UAuraAttributeSet::GetVigorAttribute();
	VigorDef.AttributeSource = EGameplayEffectAttributeCaptureSource::Target;

	RelevantAttributesToCapture.Emplace(VigorDef);
}

float UMMC_MaxHealth::CalculateBaseMagnitude_Implementation(const FGameplayEffectSpec& Spec) const
{

	/*
	 * 1. Vigor 정보 가져오기
	 * 2. Level 정보 가져오기
	 * 3. resultVal = DefaultVal + Vigore * 5.5f + Level * 10.f
	 */
	

	FAggregatorEvaluateParameters EvaluateParam;
	EvaluateParam.SourceTags = Spec.CapturedSourceTags.GetAggregatedTags();
	EvaluateParam.TargetTags = Spec.CapturedTargetTags.GetAggregatedTags();

	float VigorMagnitude;
	GetCapturedAttributeMagnitude(VigorDef, Spec, EvaluateParam, VigorMagnitude);

	int32 PlayerLevel = 0;
	if (ICombatInterface* CombatInterface = Cast<ICombatInterface>(Spec.GetContext().GetSourceObject()))
	{
		PlayerLevel = CombatInterface->GetPlayerLevel();
	}
	return 80.f + VigorMagnitude * 5.f + PlayerLevel * 10.f;
}
