


#include "FT2G1_GameplayTags.h"

#include "GameplayTagsManager.h"

FT2G1_GameplayTags FT2G1_GameplayTags::GameplayTags;


void FT2G1_GameplayTags::InitializeNativeGameplayTags()
{
	//input
	GameplayTags.InputTag_LMB = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Input.LMB"));
	GameplayTags.InputTag_RMB = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Input.RMB"));
	GameplayTags.InputTag_1 = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Input.1"));
	GameplayTags.InputTag_2 = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Input.2"));
	GameplayTags.InputTag_3 = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Input.3"));
	GameplayTags.InputTag_4 = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Input.4"));
	
	//vital
	GameplayTags.Attributes_Vital_Health = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Vital.Health"));
	GameplayTags.Attributes_Vital_Mana = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Vital.Mana"));
	
	//secondary
	GameplayTags.Attributes_Secondary_MaxHealth =  UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.MaxHealth"));
	GameplayTags.Attributes_Secondary_MaxMana = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.MaxMana"));
	GameplayTags.Attributes_Secondary_Armour = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.Armour"));
	GameplayTags.Attributes_Secondary_ArmourPenetration =  UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.ArmourPenetration"));
	GameplayTags.Attributes_Secondary_BlockChance =  UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.BlockChance"));
	GameplayTags.Attributes_Secondary_CriticalHitChance = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.CriticalHitChance"));
	GameplayTags.Attributes_Secondary_CriticalHitDamage = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.CriticalHitDamage"));

	//damge
	GameplayTags.FireAbility = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("FireAbility"));
	GameplayTags.SpellAbility = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("SpellAbility"));
	
}
