// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "TempoBPLibrary.h"
#include "Tempo.h"

UTempoBPLibrary::UTempoBPLibrary(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{

}

void UTempoBPLibrary::LaunchExternalExecutable(const FString& FilePath, const TArray<FString>& Parameters)
{
    FString Command = FString::Printf(TEXT("\"%s\""), *FilePath);

    for (const FString& Param : Parameters)
    {
        Command += FString::Printf(TEXT(" %s"), *Param);
    }

    FProcHandle ProcessHandle = FPlatformProcess::CreateProc(*FilePath, *Command, true, false, false, nullptr, 0, nullptr, nullptr);

    if (!ProcessHandle.IsValid())
    {
        UE_LOG(LogTemp, Error, TEXT("Failed to launch executable: %s"), *FilePath);
    }
}