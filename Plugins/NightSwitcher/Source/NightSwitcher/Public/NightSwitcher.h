// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

class FToolBarBuilder;
class FMenuBuilder;

class FNightSwitcherModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
	
	/** This function will be bound to Command. */
	void PluginButtonClicked();
	
private:

	void RegisterMenus();

	bool bIsNight = false;
	AActor* FindActor(TSubclassOf<AActor> ActorClass);
	AActor* AddActor(TSubclassOf<AActor> ActorClass);

	void SetDirectionalLightIntensity(bool status, float Intensity);
	void ConfigurePPvol(bool status, AActor* FoundActor);

	void SwitchFromDay();
	void SwitchFromNight();


private:
	TSharedPtr<class FUICommandList> PluginCommands;
};
