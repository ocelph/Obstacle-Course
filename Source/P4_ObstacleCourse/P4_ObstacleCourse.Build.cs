// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class P4_ObstacleCourse : ModuleRules
{
	public P4_ObstacleCourse(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"P4_ObstacleCourse",
			"P4_ObstacleCourse/Variant_Platforming",
			"P4_ObstacleCourse/Variant_Platforming/Animation",
			"P4_ObstacleCourse/Variant_Combat",
			"P4_ObstacleCourse/Variant_Combat/AI",
			"P4_ObstacleCourse/Variant_Combat/Animation",
			"P4_ObstacleCourse/Variant_Combat/Gameplay",
			"P4_ObstacleCourse/Variant_Combat/Interfaces",
			"P4_ObstacleCourse/Variant_Combat/UI",
			"P4_ObstacleCourse/Variant_SideScrolling",
			"P4_ObstacleCourse/Variant_SideScrolling/AI",
			"P4_ObstacleCourse/Variant_SideScrolling/Gameplay",
			"P4_ObstacleCourse/Variant_SideScrolling/Interfaces",
			"P4_ObstacleCourse/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
