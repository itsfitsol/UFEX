// Fill out your copyright notice in the Description page of Project Settings.

#include "UFEXSampleGameInstance.h"
#include "DataTableManager.h"

DEFINE_LOG_CATEGORY_STATIC(UFEXTextLog, Log, Log);

void UUFEXSampleGameInstance::Init()
{
	/**
	 * TODO
	 * - Templatize UDataTableManager::GetData()
	 * - Move soft referencing into UDataTableManager
	 */

	UDataTable* TestDataTable = nullptr;
	if (SoftTestDataTable.IsPending())
	{
		TestDataTable = SoftTestDataTable.LoadSynchronous();
	}
	
	static const FName TestTableName(TEXT("Test"));
	UDataTableManager::Get()->TestAddDataTable(TestTableName, TestDataTable);

	static const FName TestDataName(TEXT("RowData00"));
	const FTableRowBase* const TestData = UDataTableManager::Get()->GetData(TestTableName, TestDataName);
		
	if (TestData)
	{
		UE_LOG(UFEXTextLog, Log, TEXT("GetData() is succeeded!"));
	}
	else
	{
		UE_LOG(UFEXTextLog, Log, TEXT("GetData() is failed!"));
	}
}
