// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Classroom : ModuleRules
{
	public Classroom(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "UMG" });
        PrivateDependencyModuleNames.AddRange(new string[] { "PlayFab", "PlayFabCpp", "PlayFabCommon" });

        MinFilesUsingPrecompiledHeaderOverride = 1;
        bFasterWithoutUnity = true;
    }
}
