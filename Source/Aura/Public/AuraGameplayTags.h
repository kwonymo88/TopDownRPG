// Copyright TazoGom Soft

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
struct FAuraGameplayTags
{
public:
 static FAuraGameplayTags& Get() { return AuraGameplayTags; }
 static void InitilaizeAuraGameplayTags();
protected:
private:
 static FAuraGameplayTags AuraGameplayTags;
};
