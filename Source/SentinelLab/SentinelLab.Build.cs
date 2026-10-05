// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class SentinelLab : ModuleRules
{
	public SentinelLab(ReadOnlyTargetRules Target) : base(Target)
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
			"SentinelLab",
			"SentinelLab/Variant_Horror",
			"SentinelLab/Variant_Horror/UI",
			"SentinelLab/Variant_Shooter",
			"SentinelLab/Variant_Shooter/AI",
			"SentinelLab/Variant_Shooter/UI",
			"SentinelLab/Variant_Shooter/Weapons"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
