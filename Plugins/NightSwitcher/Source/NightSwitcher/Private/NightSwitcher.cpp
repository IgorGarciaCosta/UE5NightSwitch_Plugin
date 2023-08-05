// Copyright Epic Games, Inc. All Rights Reserved.

#include "NightSwitcher.h"
#include "NightSwitcherStyle.h"
#include "NightSwitcherCommands.h"
#include "Misc/MessageDialog.h"
#include "ToolMenus.h"

static const FName NightSwitcherTabName("NightSwitcher");

#define LOCTEXT_NAMESPACE "FNightSwitcherModule"

void FNightSwitcherModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	
	FNightSwitcherStyle::Initialize();
	FNightSwitcherStyle::ReloadTextures();

	FNightSwitcherCommands::Register();
	
	PluginCommands = MakeShareable(new FUICommandList);

	PluginCommands->MapAction(
		FNightSwitcherCommands::Get().PluginAction,
		FExecuteAction::CreateRaw(this, &FNightSwitcherModule::PluginButtonClicked),
		FCanExecuteAction());

	UToolMenus::RegisterStartupCallback(FSimpleMulticastDelegate::FDelegate::CreateRaw(this, &FNightSwitcherModule::RegisterMenus));
}

void FNightSwitcherModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.

	UToolMenus::UnRegisterStartupCallback(this);

	UToolMenus::UnregisterOwner(this);

	FNightSwitcherStyle::Shutdown();

	FNightSwitcherCommands::Unregister();
}

void FNightSwitcherModule::PluginButtonClicked()
{
	// Put your "OnButtonClicked" stuff here
	FText DialogText = FText::Format(
							LOCTEXT("PluginButtonDialogText", "Add code to {0} in {1} to override this button's actions"),
							FText::FromString(TEXT("FNightSwitcherModule::PluginButtonClicked()")),
							FText::FromString(TEXT("NightSwitcher.cpp"))
					   );
	FMessageDialog::Open(EAppMsgType::Ok, DialogText);
}

void FNightSwitcherModule::RegisterMenus()
{
	// Owner will be used for cleanup in call to UToolMenus::UnregisterOwner
	FToolMenuOwnerScoped OwnerScoped(this);

	{
		UToolMenu* Menu = UToolMenus::Get()->ExtendMenu("LevelEditor.MainMenu.Window");
		{
			FToolMenuSection& Section = Menu->FindOrAddSection("WindowLayout");
			Section.AddMenuEntryWithCommandList(FNightSwitcherCommands::Get().PluginAction, PluginCommands);
		}
	}

	{
		UToolMenu* ToolbarMenu = UToolMenus::Get()->ExtendMenu("LevelEditor.LevelEditorToolBar.PlayToolBar");
		{
			FToolMenuSection& Section = ToolbarMenu->FindOrAddSection("PluginTools");
			{
				FToolMenuEntry& Entry = Section.AddEntry(FToolMenuEntry::InitToolBarButton(FNightSwitcherCommands::Get().PluginAction));
				Entry.SetCommandList(PluginCommands);
			}
		}
	}
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FNightSwitcherModule, NightSwitcher)