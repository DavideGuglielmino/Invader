// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Invader : ModuleRules
{
	public Invader(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[]
        {
            "Core",
            "CoreUObject",
            "Engine",
            "InputCore",
        });
	}
}
