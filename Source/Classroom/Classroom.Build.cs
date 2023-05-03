// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Classroom : ModuleRules
{
	public Classroom(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "UMG", "PlayFab","PlayFabCpp", "PlayFabCommon" });
        PrivateDependencyModuleNames.AddRange(new string[] {  });

        MinFilesUsingPrecompiledHeaderOverride = 1;
        bFasterWithoutUnity = true;
    }
}
