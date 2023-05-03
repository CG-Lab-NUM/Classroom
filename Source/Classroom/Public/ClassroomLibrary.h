// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "ClassroomLibrary.generated.h"

DECLARE_DYNAMIC_DELEGATE(FExecuteDelegate);
DECLARE_DYNAMIC_DELEGATE_OneParam(FForLoopDelegate, int, index);

UCLASS()
class CLASSROOM_API UClassroomLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable, Category = "Interpreter")
	static void classForLoop(int initial, int final, int iter, FForLoopDelegate execute);

};
