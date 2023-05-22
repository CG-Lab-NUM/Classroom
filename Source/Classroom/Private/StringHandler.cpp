#include "StringHandler.h"

// Sets default values
AStringHandler::AStringHandler()
{
	PrimaryActorTick.bCanEverTick = true;

}

void AStringHandler::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AStringHandler::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

int AStringHandler::getStringLineCount(FString string) {
	int lineCount = 0;
	for (int i = 0; i < string.Len(); i++) {
		if (string.Mid(i, 1).Equals("\n")) {
			lineCount++;
		}
	}
	return lineCount;
}

