// Copyright Epic Games, Inc. All Rights Reserved.

#include "NightSwitcher.h"
#include "NightSwitcherStyle.h"
#include "NightSwitcherCommands.h"
#include "Misc/MessageDialog.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/DirectionalLight.h"
#include "Components/LightComponent.h"
#include "Engine/PostProcessVolume.h"
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
	/*FText DialogText = FText::FromString("Change sky Time");
	FMessageDialog::Open(EAppMsgType::OkCancel, DialogText);*/

	if (!bIsNight) {
		FText DialogText = FText::FromString(TEXT("Changing sky Time"));
		EAppReturnType::Type ReturnType = FMessageDialog::Open(EAppMsgType::OkCancel, DialogText);

		//clicked OK
		if (ReturnType == EAppReturnType::Ok)
		{
			SwitchFromDay();
		}
		//clicked Cancel
		else if (ReturnType == EAppReturnType::Cancel)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("Cancelled"));
		}
	}
	
	
	
	//clicked OK, but its night already
	else if (bIsNight) {
		//set directional light again to 1
		//destroy ppvol
		SwitchFromNight();

	}
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

AActor* FNightSwitcherModule::FindActor(TSubclassOf<AActor> ActorClass)
{
	TArray<AActor*> FoundActors;
	UWorld* World = GEditor->GetEditorWorldContext().World();
	if (World) {
		UGameplayStatics::GetAllActorsOfClass(World, ActorClass, FoundActors);
		if (FoundActors.Num()>0) {
			return FoundActors[0];
		}
	}
	return nullptr;
}

AActor* FNightSwitcherModule::AddActor(TSubclassOf<AActor> ActorClass)
{
	ULevel* Level = GEditor->GetEditorWorldContext().World()->GetCurrentLevel();
	return GEditor->AddActor(Level, ActorClass, FTransform());

}

void FNightSwitcherModule::SetDirectionalLightIntensity(bool status, float Intensity)
{
	//changes sky time
	AActor* FoundActor;
	FoundActor = FindActor(ADirectionalLight::StaticClass());

	if (FoundActor) {
		ADirectionalLight* sun = Cast<ADirectionalLight>(FoundActor);
		if (sun) {
			sun->GetLightComponent()->SetIntensity(Intensity);
			bIsNight = status;
		}
	}
}

void FNightSwitcherModule::ConfigurePPvol(bool status, AActor* FoundActor)
{
	APostProcessVolume* PPVol;
	PPVol = Cast< APostProcessVolume>(FoundActor);
	//is day
	if (!status) {
		//configures ppvolume
		
		PPVol->Settings.AutoExposureBias = -3.f;
		PPVol->Settings.bOverride_AutoExposureBias = true;
		PPVol->bUnbound = true;//finite extent
	}

	//is night
	else {
		PPVol->Destroy();
	}
	
}



void FNightSwitcherModule::SwitchFromDay()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("Activated"));

	SetDirectionalLightIntensity(true,0.2f);

	

	AActor* FoundActor = FindActor(APostProcessVolume::StaticClass());
	if (!FoundActor) {
		FText DialogText = FText::FromString("Post Process volume not found! Creating One");
		FMessageDialog::Open(EAppMsgType::Ok, DialogText);
		FoundActor = AddActor(APostProcessVolume::StaticClass());
	}

	ConfigurePPvol(false, FoundActor);
	
}

void FNightSwitcherModule::SwitchFromNight()
{
	SetDirectionalLightIntensity(false, 1.f);
	AActor* FoundActor = FindActor(APostProcessVolume::StaticClass());
	if (FoundActor) {
		ConfigurePPvol(true, FoundActor);
	}
	
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FNightSwitcherModule, NightSwitcher)