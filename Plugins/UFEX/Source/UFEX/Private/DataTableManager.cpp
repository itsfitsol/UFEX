// Fill out your copyright notice in the Description page of Project Settings.

#include "DataTableManager.h"
#include "IUFEXPlugin.h"
#include "DataTableSettings.h"

DEFINE_LOG_CATEGORY_STATIC(UFEXLog, Log, Log);

TWeakObjectPtr<UDataTableManager> UDataTableManager::Instance = TWeakObjectPtr<UDataTableManager>();

UDataTableManager::UDataTableManager()
	: bIsInitialized(false)
{
	
}

void UDataTableManager::Initialize()
{
	if (bIsInitialized)
	{
		return;
	}

	TableMap.Reset();
	
	const TArray<FLoadingSetup>& LoadingSetups = UDataTableSettings::Get()->LoadingSetups;
	for (const auto& Setup : LoadingSetups)
	{
		TableMap.Add(Setup.Name, Setup.Resource.LoadSynchronous());
	}

	bIsInitialized = true;
}

bool UDataTableManager::IsInitialized() const
{
	return bIsInitialized;
}

UDataTableManager* UDataTableManager::Get()
{
	if (!UDataTableManager::Instance.IsValid())
	{
		UDataTableManager::Instance = IUFEXPlugin::Get().GetDataTableManager();
	}

	if (!UDataTableManager::Instance->IsInitialized())
	{
		UDataTableManager::Instance->Initialize();
	}

	return UDataTableManager::Instance.Get();
}
