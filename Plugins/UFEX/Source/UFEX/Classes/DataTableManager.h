// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DataTableManager.generated.h"


UCLASS()
class UFEX_API UDataTableManager : public UObject
{
	GENERATED_BODY()

public:

	UDataTableManager();

	void Initialize();

	/** For the basic test to get data */
	void TestAddDataTable(const FName& TableName, class UDataTable* Table);

	const struct FTableRowBase* const GetData(const FName& TableName, const FName& DataName) const;

private:

	bool bIsInitialized;

	/** Actual data table map */
	UPROPERTY()
	TMap<FName, UDataTable*> TableMap;

	/** Statics */
public:
	static UDataTableManager* Get();

private:
	static TWeakObjectPtr<UDataTableManager> Instance;
};
