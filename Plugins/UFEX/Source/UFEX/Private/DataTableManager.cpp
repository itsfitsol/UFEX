// Fill out your copyright notice in the Description page of Project Settings.

#include "DataTableManager.h"
#include "IUFEXPlugin.h"

DEFINE_LOG_CATEGORY_STATIC(UFEXLog, Log, Log);

TWeakObjectPtr<UDataTableManager> UDataTableManager::Instance = TWeakObjectPtr<UDataTableManager>();

UDataTableManager::UDataTableManager()
	: bIsInitialized(false)
{
	
}

void UDataTableManager::Initialize()
{
	bIsInitialized = true;
}

bool UDataTableManager::IsInitialized() const
{
	return bIsInitialized;
}

void UDataTableManager::TestAddDataTable(const FName& TableName, UDataTable* Table)
{
	if (!Table || !TableName.IsNone())
	{
		return;
	}

	// Check if the table is valid as an Asset managed by Unreal.
	check(Table->IsValidLowLevel());

	if (!TableMap.Contains(TableName))
	{
		TableMap.Add(TableName, Table);
	}
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
