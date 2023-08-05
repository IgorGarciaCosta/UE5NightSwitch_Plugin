// Copyright Epic Games, Inc. All Rights Reserved.

#include "NightSwitcherCommands.h"

#define LOCTEXT_NAMESPACE "FNightSwitcherModule"

void FNightSwitcherCommands::RegisterCommands()
{
	UI_COMMAND(PluginAction, "NightSwitcher", "Execute NightSwitcher action", EUserInterfaceActionType::Button, FInputChord());
}

#undef LOCTEXT_NAMESPACE
