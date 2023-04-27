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

FString AFileHandler::loadFileToString(FString filepath) {
	FString fullPath = FPaths::Combine(FPaths::ConvertRelativePathToFull(FPaths::ProjectSavedDir()), filepath);
	FString fileContents;
	if (FFileHelper::LoadFileToString(fileContents, *fullPath)) {
		return fileContents;
	}
	return "";
}

FString AFileHandler::loadFileFromDialog() {
	FString defaultPath = FPaths::ProjectSavedDir();
	FString fileTypes = "All Files (*.*)|*.*";
	TArray<FString> outFileNames;

	IDesktopPlatform* desktopPlatform = FDesktopPlatformModule::Get();
	if (desktopPlatform) {
		bool bResult = desktopPlatform->OpenFileDialog(
			nullptr,
			"Select a file",
			defaultPath,
			"",
			TEXT(";;") + fileTypes,
			EFileDialogFlags::None,
			outFileNames
		);

		if (bResult && outFileNames.Num() > 0) {
			return outFileNames[0];
		}
	}
	return "";
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