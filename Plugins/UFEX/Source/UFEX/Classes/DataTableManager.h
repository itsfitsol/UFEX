// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "DataTableManager.generated.h"


UCLASS()
class UFEX_API UDataTableManager : public UObject
{
	GENERATED_BODY()

public:

	UDataTableManager();

	void Initialize();

	bool IsInitialized() const;

	/** For the basic test to get data */
	void TestAddDataTable(const FName& TableName, UDataTable* Table);
	
private:

	bool bIsInitialized;

	/** Actual data table map */
	UPROPERTY()
	TMap<FName, UDataTable*> TableMap;

	/** Statics */
public:

	/** Get data directly from specific data table */
	template <typename TTableRow>
	static const typename TEnableIf<TIsDerivedFrom<TTableRow, FTableRowBase>::IsDerived, TTableRow>::Type* const 
		GetTableRow(const FName& TableName, const FName& RowName)
	{
		const UDataTable* const DataTable = UDataTableManager::GetDataTable(TableName);
		if (IsValid(DataTable))
		{
			return DataTable->FindRow<TTableRow>(RowName, TEXT("UFEX::UDataTableManager::GetTableRow()"));
		}

		return nullptr;
	}

	/** Get specific data table */
	static const UDataTable* const GetDataTable(const FName& TableName)
	{
		UDataTableManager* Manager = UDataTableManager::Get();
		if (!IsValid(Manager))
		{
			return nullptr;
		}

		UDataTable** DataTablePtr = Manager->TableMap.Find(TableName);
		if (!DataTablePtr)
		{
			return nullptr;
		}

		return *DataTablePtr;
	}

	static UDataTableManager* Get();

private:
	static TWeakObjectPtr<UDataTableManager> Instance;
};
