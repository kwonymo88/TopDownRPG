// Copyright TazoGom Soft


#include "AuraGameplayTags.h"

#include "GameplayTagsManager.h"

FAuraGameplayTags FAuraGameplayTags::AuraGameplayTags;

void FAuraGameplayTags::InitilaizeAuraGameplayTags()
{
	UGameplayTagsManager::Get().AddNativeGameplayTag(TEXT("Attributes.Secondary.Armor"), FString("Reduces damage taken, improves Block Chance"));
}
