// Fill out your copyright notice in the Description page of Project Settings.

namespace UnrealBuildTool.Rules
{
	public class UFEX : ModuleRules
	{
		public UFEX(ReadOnlyTargetRules Target) : base(Target)
		{
			PublicIncludePaths.AddRange(
				new string[] {
				}
				);

			PrivateIncludePaths.AddRange(
				new string[] {
				}
				);

			PublicDependencyModuleNames.AddRange(
				new string[]
				{
					"Core"
				}
				);

			PrivateDependencyModuleNames.AddRange(
				new string[]
				{
                    "CoreUObject",
                    "Engine"
				}
				);

			DynamicallyLoadedModuleNames.AddRange(
				new string[]
				{
				}
				);
		}
	}
}
