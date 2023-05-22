// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "StringHandler.generated.h"

UCLASS()
class CLASSROOM_API AStringHandler : public AActor
{
	GENERATED_BODY()
	
public:	
	AStringHandler();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = "String")
		int getStringLineCount(FString string);

};
