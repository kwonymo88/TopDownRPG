// Copyright TazoGom Soft


#include "AuraGameplayTags.h"

#include "GameplayTagsManager.h"

FAuraGameplayTags FAuraGameplayTags::AuraGameplayTags;

void FAuraGameplayTags::InitilaizeAuraGameplayTags()
{
	AuraGameplayTags.Attributes_Primary_Strength = UGameplayTagsManager::Get().AddNativeGameplayTag(TEXT("Attributes.Primary.Strength"), FString("Increase Physical Damage"));
	AuraGameplayTags.Attributes_Primary_Intelligence = UGameplayTagsManager::Get().AddNativeGameplayTag(TEXT("Attributes.Primary.Intelligence"), FString("Increase Magical Damage"));
	AuraGameplayTags.Attributes_Primary_Resilience = UGameplayTagsManager::Get().AddNativeGameplayTag(TEXT("Attributes.Primary.Resilience"), FString("Increase armor and armor penetration"));
	AuraGameplayTags.Attributes_Primary_Vigor = UGameplayTagsManager::Get().AddNativeGameplayTag(TEXT("Attributes.Primary.Vigor"), FString("Increase health"));

	AuraGameplayTags.Attributes_Secondary_Armor = UGameplayTagsManager::Get().AddNativeGameplayTag(TEXT("Attributes.Secondary.Armor"), FString("Reduces damage taken, improves Block Chance"));
	AuraGameplayTags.Attributes_Secondary_ArmorPenetration = UGameplayTagsManager::Get().AddNativeGameplayTag(TEXT("Attributes.Secondary.ArmorPenetration"), FString(""));
	AuraGameplayTags.Attributes_Secondary_BlockChance = UGameplayTagsManager::Get().AddNativeGameplayTag(TEXT("Attributes.Secondary.BlockChance"), FString(""));
	AuraGameplayTags.Attributes_Secondary_CriticalHitChance = UGameplayTagsManager::Get().AddNativeGameplayTag(TEXT("Attributes.Secondary.CriticalHitChance"), FString(""));
	AuraGameplayTags.Attributes_Secondary_CriticalHitDamage = UGameplayTagsManager::Get().AddNativeGameplayTag(TEXT("Attributes.Secondary.CriticalHitDamage"), FString(""));
	AuraGameplayTags.Attributes_Secondary_CriticalHitResistance = UGameplayTagsManager::Get().AddNativeGameplayTag(TEXT("Attributes.Secondary.CriticalHitResistance"), FString(""));
	AuraGameplayTags.Attributes_Secondary_HealthRegeneration = UGameplayTagsManager::Get().AddNativeGameplayTag(TEXT("Attributes.Secondary.HealthRegeneration"), FString(""));
	AuraGameplayTags.Attributes_Secondary_ManaRegeneration = UGameplayTagsManager::Get().AddNativeGameplayTag(TEXT("Attributes.Secondary.ManaRegeneration"), FString(""));
	AuraGameplayTags.Attributes_Secondary_MaxHealth = UGameplayTagsManager::Get().AddNativeGameplayTag(TEXT("Attributes.Secondary.MaxHealth"), FString(""));
	AuraGameplayTags.Attributes_Secondary_MaxMana = UGameplayTagsManager::Get().AddNativeGameplayTag(TEXT("Attributes.Secondary.MaxMana"), FString(""));

}
