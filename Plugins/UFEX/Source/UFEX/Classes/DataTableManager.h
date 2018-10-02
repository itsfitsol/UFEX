// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DataTableManager.generated.h"

/**
* Functionalities to be developed
* 1. Interfaces for default behaviors (Initialization for data tables, Data reading, etc..)
* 2. Table settings (Lazy loading for each data table and each row)
*/


UCLASS()
class UFEX_API UDataTableManager : public UObject
{
	GENERATED_BODY()

public:
	UDataTableManager();

	void Initialize();

	static UDataTableManager* Get();

private:
	/** Whether the instance of DataTableManager is initialized */
	bool bIsInitialized;
	
private:
	static TWeakObjectPtr<UDataTableManager> Instance;
};
