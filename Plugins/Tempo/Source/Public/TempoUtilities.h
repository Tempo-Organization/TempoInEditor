#pragma once

#include "Json.h"
#include "Runtime/JsonUtilities/Public/JsonUtilities.h"
#include "Engine/DataTable.h"
#include "TempoUtilities.generated.h"

UCLASS()
class TEMPO_API UTempoUtilities : public UObject
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, Category = "Tempo")
		static void LaunchExternalExecutable(const FString& FilePath, const TArray<FString>& Parameters);

	UFUNCTION(BlueprintCallable, Category = "Tempo")
		static void LaunchExternalExecutableNoHead(const FString& FilePath, const TArray<FString>& Parameters);

    UFUNCTION(BlueprintCallable, Category = "Tempo")
		static FString GetProjectDirectory();

    UFUNCTION(BlueprintCallable, Category = "Tempo")
		static TArray<FString> GetFilesInDirectoryTree(const FString& Directory);

    UFUNCTION(BlueprintCallable, Category = "Tempo")
		static TArray<FString> GetFileExtensionsFromPaths(const TArray<FString>& FilePaths);

    UFUNCTION(BlueprintCallable, Category = "Tempo")
		static bool CreateDirectory(const FString& Directory);

    UFUNCTION(BlueprintCallable, Category = "Tempo")
		static bool DeleteDirectoryAndContents(const FString& Directory);

    UFUNCTION(BlueprintCallable, Category = "Tempo")
		static bool DoesDirectoryExist(const FString& Directory);

    UFUNCTION(BlueprintCallable, Category = "Tempo")
		static bool DoesFileExist(const FString& File);

    UFUNCTION(BlueprintCallable, Category = "Tempo")
		static bool CopyFile(const FString& BeforeFile, const FString& AfterFile);

    UFUNCTION(BlueprintCallable, Category = "Tempo")
		static bool DeleteFile(const FString& File);

    UFUNCTION(BlueprintCallable, Category = "Tempo")
		static FString DataTableToJson(UDataTable* DataTable);

    UFUNCTION(BlueprintCallable, Category = "Tempo")
		static bool JsonToDataTable(const FString& JsonString, UDataTable* DataTable);

    UFUNCTION(BlueprintCallable, Category = "Tempo")
		static bool CreateTextFile(const FString& FileName, const FString& FileContents);

    UFUNCTION(BlueprintCallable, Category = "Tempo")
		static FString ReadFile(const FString& FileName);

    UFUNCTION(BlueprintCallable, Category = "Tempo")
		static TArray<FString> GetFunctionNames(UObject* Object);

    UFUNCTION(BlueprintCallable, Category = "Tempo")
		static void CallFunctionByName(UObject* Object, const FString& FunctionName);

    UFUNCTION(BlueprintCallable, Category = "Tempo")
		static TArray<UObject*> GetAllInstancedObjectsOfClass(UClass* Class);

    UFUNCTION(BlueprintCallable, Category = "Tempo")
        static TArray<FString> GetEnumValuesAsString(UEnum* Enum);

    UFUNCTION(BlueprintCallable, Category = "Tempo")
        static void OpenDirectory(FString DirectoryPath);

    UFUNCTION(BlueprintCallable, Category = "Tempo")
        static void OpenWebsite(FString URL);

    UFUNCTION(BlueprintCallable, Category = "Tempo")
        static bool SetJsonFieldAsString(const FString& JsonString, const TArray<FString>& FieldNames, const FString& FieldValue, FString& OutJsonString);

    UFUNCTION(BlueprintCallable, Category = "Tempo")
        static bool GetJsonFieldAsString(const FString& JsonString, const TArray<FString>& FieldNames, FString& FieldValue);

    UFUNCTION(BlueprintCallable, Category = "Tempo")
        static bool WriteStringToFile(const FString& FileName, const FString& FileContents);

    UFUNCTION(BlueprintCallable, Category = "Tempo")
        static bool RemoveJsonField(const FString& JsonString, const TArray<FString>& FieldNames, FString& OutJsonString);

    UFUNCTION(BlueprintCallable, Category = "Tempo")
        static bool ReadJsonField(const FString& JsonString, const TArray<FString>& FieldNames, FString& FieldValue);

    UFUNCTION(BlueprintCallable, Category = "Tempo")
        static bool AddJsonListEntry(const FString& JsonString, const TArray<FString>& FieldNames, const FString& EntryValue, FString& OutJsonString);

    UFUNCTION(BlueprintCallable, Category = "Tempo")
        static bool RemoveJsonListEntry(const FString& JsonString, const TArray<FString>& FieldNames, int32 Index, FString& OutJsonString);

    UFUNCTION(BlueprintCallable, Category = "Tempo")
        static bool GetJsonArrayEntries(const FString& JsonString, const TArray<FString>& FieldNames, TArray<FString>& Entries);

    UFUNCTION(BlueprintCallable, Category = "Tempo")
        static bool CheckIfJsonFieldExists(const FString& JsonString, const TArray<FString>& FieldNames, bool& Exists);

	UFUNCTION(BlueprintCallable, Category = "Tempo")
		static FString GetParentDirectory(const FString& FilePath);
};