// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ChemistryHandler.generated.h"


UCLASS()
class CLASSROOM_API AChemistryHandler : public AActor
{
	GENERATED_BODY()
	
public:	
	AChemistryHandler();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = "Chemistry")
		TArray<FString> handleReaction(TArray<FString> arr);

	bool countStringInstances(const TArray<FString>& stringArray, const FString& searchString, int32 numInstances);

};
