// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Team2Game1 : ModuleRules
{
	public Team2Game1(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput", "GameplayAbilities","GameplayTags", "Niagara" });

		PrivateDependencyModuleNames.AddRange(new string[] {  "GameplayTasks","NavigationSystem", "Niagara", "AIModule" });
		PrivateDependencyModuleNames.AddRange(new string[] { "AnimGraphRuntime" });
	}
}
