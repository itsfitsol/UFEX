// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "DataTableSettings.generated.h"

USTRUCT()
struct FLoadingSetup
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly)
	FName Name;

	UPROPERTY(EditDefaultsOnly)
	TSoftObjectPtr<class UDataTable> Resource;

	FLoadingSetup()
		: Name(NAME_None)
		, Resource(nullptr)
	{}
};

UCLASS(config = Game, defaultconfig, meta = (DisplayName = "UFEX", ToolTip = "Settings for DataTableManager to manage tables"))
class UFEX_API UDataTableSettings : public UDeveloperSettings
{
	GENERATED_BODY()

public:
	UDataTableSettings();

public:
	UPROPERTY(EditAnywhere, Config, Category = "Data Table")
	TArray<FLoadingSetup> LoadingSetups;

public:
	static UDataTableSettings* Get() { return CastChecked<UDataTableSettings>(UDataTableSettings::StaticClass()->GetDefaultObject()); }
};
