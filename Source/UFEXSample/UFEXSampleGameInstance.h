// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Engine/DataTable.h"
#include "UFEXSampleGameInstance.generated.h"

USTRUCT()
struct FTestDataTableRow : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	int32 IntData;
};

/**
 * 
 */
UCLASS()
class UFEXSAMPLE_API UUFEXSampleGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:
	virtual void Init() override;
};
