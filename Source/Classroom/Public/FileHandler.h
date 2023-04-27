// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GenericPlatform/GenericPlatformFile.h"
#include "HAL/PlatformFileManager.h"
#include "DesktopPlatform/Public/DesktopPlatformModule.h"
#include "FileHandler.generated.h"

UCLASS()
class CLASSROOM_API AFileHandler : public AActor
{
	GENERATED_BODY()
	
public:	
	AFileHandler();

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

public:
	UFUNCTION(BlueprintCallable, Category = "File")
		TArray<FString> getFilesInFolder(FString path);
	UFUNCTION(BlueprintCallable, Category = "File")
		FString getPlatform();
	UFUNCTION(BlueprintCallable, Category = "File")
		FString loadFileToString(FString filepath);
	UFUNCTION(BlueprintCallable, Category = "File")
		FString loadFileFromDialog();
};
