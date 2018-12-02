// Fill out your copyright notice in the Description page of Project Settings.

#include "UFEXSampleGameInstance.h"
#include "DataTableManager.h"

DEFINE_LOG_CATEGORY_STATIC(UFEXTextLog, Log, Log);

void UUFEXSampleGameInstance::Init()
{
	/**
	 * TODO
	 * - Move soft referencing into UDataTableManager
	 */

	if (SoftTestDataTable.IsPending())
	{
		SoftTestDataTable.LoadSynchronous();
	}
	
	static const FName TestTableName(TEXT("Test"));
	UDataTableManager::Get()->TestAddDataTable(TestTableName, SoftTestDataTable.Get());

	static const FName TestDataName(TEXT("RowData00"));
	const FTestDataTableRow* const TestData = UDataTableManager::GetTableRow<FTestDataTableRow>(TestTableName, TestDataName);
		
	if (TestData)
	{
		UE_LOG(UFEXTextLog, Log, TEXT("GetData() is succeeded!"));
	}
	else
	{
		UE_LOG(UFEXTextLog, Log, TEXT("GetData() is failed!"));
	}
}
