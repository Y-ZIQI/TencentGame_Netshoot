// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GenericPlatform/GenericPlatformFile.h"
#include "Misc/FileHelper.h"
#include "MySaveObject.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType)
class NETSHOOT_API UMySaveObject : public UObject
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString FilePath;

	UFUNCTION(BlueprintCallable)
	void SaveGame(FString Name, int32 Score);

	UFUNCTION(BlueprintCallable)
	TArray<FString> LoadScore();
};
