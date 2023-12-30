// Copyright Epic Games, Inc. All Rights Reserved.

#include "PIEAutosave.h"
#include "Framework/Application/SlateApplication.h"
#include "Editor.h"
#include "FileHelpers.h"

#define LOCTEXT_NAMESPACE "FPIEAutosaveModule"


void FPIEAutosaveModule::StartupModule()
{
	FWorldDelegates::OnPreWorldInitialization.AddRaw(this, &FPIEAutosaveModule::OnPreWorldInitialization);
}

void FPIEAutosaveModule::ShutdownModule()
{
	FWorldDelegates::OnPreWorldInitialization.RemoveAll(this);
}

void FPIEAutosaveModule::OnPreWorldInitialization(UWorld* World, FWorldInitializationValues WorldInitializationValues)
{
	if (GEditor->IsPlayingSessionInEditor())
	{
        const bool bPromptUserToSave = true;
        const bool bSaveMapPackages = true;
        const bool bSaveContentPackages = true;
        const bool bFastSave = false;
        const bool bNotifyNoPackagesSaved = false;
        const bool bCanBeDeclined = false;
        if (!FEditorFileUtils::SaveDirtyPackages(bPromptUserToSave, bSaveMapPackages, bSaveContentPackages, bFastSave, bNotifyNoPackagesSaved, bCanBeDeclined))
        {
            UE_LOG(LogTemp, Warning, TEXT("Failed to save dirty packages"));
        }
	}
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FPIEAutosaveModule, PIEAutosave)