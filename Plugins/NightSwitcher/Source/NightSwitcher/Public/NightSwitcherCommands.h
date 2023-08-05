// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Framework/Commands/Commands.h"
#include "NightSwitcherStyle.h"

class FNightSwitcherCommands : public TCommands<FNightSwitcherCommands>
{
public:

	FNightSwitcherCommands()
		: TCommands<FNightSwitcherCommands>(TEXT("NightSwitcher"), NSLOCTEXT("Contexts", "NightSwitcher", "NightSwitcher Plugin"), NAME_None, FNightSwitcherStyle::GetStyleSetName())
	{
	}

	// TCommands<> interface
	virtual void RegisterCommands() override;

public:
	TSharedPtr< FUICommandInfo > PluginAction;
};
