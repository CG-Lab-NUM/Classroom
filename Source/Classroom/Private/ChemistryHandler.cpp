#include "ChemistryHandler.h"

AChemistryHandler::AChemistryHandler()
{
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AChemistryHandler::BeginPlay()
{
	Super::BeginPlay();
	
}


void AChemistryHandler::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

TArray<FString> AChemistryHandler::handleReaction(TArray<FString> arr) {
	TArray<FString> result;
	if (arr.Contains("O") && countStringInstances(arr, "H", 2) && arr.Num() == 3) {
		result.Add("Liquid");
		result.Add("true");
		result.Add("0.1, 0.5, 0.5");
		result.Add("H2O");
		result.Add("true"); // explosion
	}
	else if (arr.Contains("N") && countStringInstances(arr, "O", 2) && arr.Num() == 3) {
		result.Add("Liquid");
		result.Add("false");
		result.Add("1, 0.1, 0.1");
		result.Add("N2O");
		result.Add("false"); // explosion
	}
	return result;
}

bool AChemistryHandler::countStringInstances(const TArray<FString>& stringArray, const FString& searchString, int32 numInstances)
{
	int32 count = stringArray.FilterByPredicate([&searchString](const FString& el) {
		return el == searchString;
	}).Num();

	return count == numInstances;
}