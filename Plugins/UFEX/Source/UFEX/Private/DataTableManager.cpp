// Fill out your copyright notice in the Description page of Project Settings.

#include "DataTableManager.h"
#include "Engine/DataTable.h"
#include "IUFEXPlugin.h"

DEFINE_LOG_CATEGORY_STATIC(UFEXLog, Log, Log);

TWeakObjectPtr<UDataTableManager> UDataTableManager::Instance = TWeakObjectPtr<UDataTableManager>();

UDataTableManager::UDataTableManager()
	: bIsInitialized(false)
{
	
}

void UDataTableManager::Initialize()
{
	// TODO: Initialize something..
	bIsInitialized = true;
}

UDataTableManager* UDataTableManager::Get()
{
	if (!UDataTableManager::Instance.IsValid())
	{
		UDataTableManager::Instance = IUFEXPlugin::Get().GetDataTableManager();
		if (!UDataTableManager::Instance->bIsInitialized)
		{
			UDataTableManager::Instance->Initialize();
		}
	}

	return UDataTableManager::Instance.Get();
}