// Copyright TazoGom Soft


#include "AbilitySystem/AttributeInfo.h"

FAuraAttributeInfo UAttributeInfo::FindAttributeInfoForTag(const FGameplayTag& AttributeTag, bool bUseLog) const
{
    for (const FAuraAttributeInfo AttributeInfo : AttributeInfos)
    {
        if (AttributeInfo.AttributeTag.MatchesTagExact(AttributeTag))
        {
            return AttributeInfo;
        }
    }

    if (bUseLog)
    {
        UE_LOG(LogTemp, Error, TEXT("Can't find info for AttributeTag [%s] on AttributeInfos [%s]"), *AttributeTag.ToString(), *GetNameSafe(this));
    }

    return FAuraAttributeInfo();
}
