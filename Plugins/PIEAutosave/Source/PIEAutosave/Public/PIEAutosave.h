// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

class FPIEAutosaveModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

	/**
	 * @brief Before PIE starts, call UE's SaveDirtyPackages to save all open assets
	 */
	void OnPreWorldInitialization(UWorld* World, FWorldInitializationValues WorldInitializationValues);
};
