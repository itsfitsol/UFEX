// Fill out your copyright notice in the Description page of Project Settings.

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"
#include "IUFEXPlugin.h"

#include "DataTableManager.h"


class FUFEXPluginImpl : public IUFEXPlugin
{
	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

public:
	virtual UDataTableManager* GetDataTableManager() override;
};

IMPLEMENT_MODULE(FUFEXPluginImpl, UFEXPlugin)



void FUFEXPluginImpl::StartupModule()
{
	// To create singleton instances
	//GetDataTableManager();
}


void FUFEXPluginImpl::ShutdownModule()
{
}

UDataTableManager* FUFEXPluginImpl::GetDataTableManager()
{
	if (!IsValid(DataTableMgr))
	{
		DataTableMgr = NewObject<UDataTableManager>();
		DataTableMgr->Initialize();
	}

	return DataTableMgr;
}


