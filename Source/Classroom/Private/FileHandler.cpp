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

TArray<FString> AFileHandler::getFilesInFolder(FString path) {
	FString platform = getPlatform();
	TArray<FString> arr;
	if (platform == "Windows") {
		IFileManager& fileManager = IFileManager::Get();
		FString savedDirectory = FPaths::Combine(FPaths::ConvertRelativePathToFull(FPaths::ProjectSavedDir()), path);
		FString extensions = "*";
		fileManager.FindFiles(arr, *savedDirectory, *extensions);
	}
	return arr;
}


void RemoveStringsNotContainingSubstring(TArray<FString>& StringArray, const FString& Substring) {
	StringArray.FilterByPredicate([&Substring](const FString& String) {
		return String.Contains(Substring);
	});
}

TArray<FString> AFileHandler::getAssetList() {
	FString platform = getPlatform();
	TArray<FString> arr;
	if (platform == "Windows") {
		IPlatformFile& PlatformFile = FPlatformFileManager::Get().GetPlatformFile();
		FString DirectoryPath = FPaths::Combine(FPaths::ProjectSavedDir(), TEXT("Assets"));
		UE_LOG(LogTemp, Warning, TEXT("Directory: %s"), *DirectoryPath);
		PlatformFile.IterateDirectoryRecursively(*DirectoryPath, [&](const TCHAR* FilenameOrDirectory, bool bIsDirectory) -> bool {
			if (!bIsDirectory) {
				FString relativePath = FilenameOrDirectory;
				FPaths::MakePathRelativeTo(relativePath, *DirectoryPath);
				arr.Add(relativePath);
			}
		return true;
		});
	}
	return arr;
}


TArray<FString> AFileHandler::getFoldersInFolder(FString path) {
	FString platform = getPlatform();
	TArray<FString> arr;
	if (platform == "Windows") {
		IFileManager& fileManager = IFileManager::Get();
		FString savedDirectory = FPaths::Combine(FPaths::ConvertRelativePathToFull(FPaths::ProjectSavedDir()), path);
		FolderVisitor FolderVisitor(arr);
		fileManager.IterateDirectory(*savedDirectory, FolderVisitor);
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