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

private:

	bool bIsInitialized;

	/** Static methods */
public:
	static UDataTableManager* Get();

private:
	static TWeakObjectPtr<UDataTableManager> Instance;
};
