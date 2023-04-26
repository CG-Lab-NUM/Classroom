#include "FileHandler.h"

AFileHandler::AFileHandler() {
	PrimaryActorTick.bCanEverTick = true;

}

void AFileHandler::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AFileHandler::BeginPlay()
{
	Super::BeginPlay();
}

TArray<FString> AFileHandler::getFilesInFolder() {
	FString platform = getPlatform();
	TArray<FString> arr;
	if (platform == "Windows") {
		IFileManager& fileManager = IFileManager::Get();
		FString savedDirectory = FPaths::ConvertRelativePathToFull(FPaths::ProjectSavedDir());
		FString extensions = "*";
		fileManager.FindFiles(arr, *savedDirectory, *extensions);
	}
	return arr;
}

FString AFileHandler::getPlatform() {
#if PLATFORM_WINDOWS
	return "Windows";
#endif
#if PLATFORM_MAC
	return "MacOS";
#endif
#if PLATFORM_LINUX
	return "Linux";
#endif
#if PLATFORM_ANDROID
	return "Android";
#endif
#if PLATFORM_IOS
	return "iOS";
#endif
	return "Unknown";
}