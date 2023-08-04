// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "NightSwitchPlugin/NightSwitchPluginGameModeBase.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeNightSwitchPluginGameModeBase() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	NIGHTSWITCHPLUGIN_API UClass* Z_Construct_UClass_ANightSwitchPluginGameModeBase();
	NIGHTSWITCHPLUGIN_API UClass* Z_Construct_UClass_ANightSwitchPluginGameModeBase_NoRegister();
	UPackage* Z_Construct_UPackage__Script_NightSwitchPlugin();
// End Cross Module References
	void ANightSwitchPluginGameModeBase::StaticRegisterNativesANightSwitchPluginGameModeBase()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ANightSwitchPluginGameModeBase);
	UClass* Z_Construct_UClass_ANightSwitchPluginGameModeBase_NoRegister()
	{
		return ANightSwitchPluginGameModeBase::StaticClass();
	}
	struct Z_Construct_UClass_ANightSwitchPluginGameModeBase_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ANightSwitchPluginGameModeBase_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_NightSwitchPlugin,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ANightSwitchPluginGameModeBase_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "NightSwitchPluginGameModeBase.h" },
		{ "ModuleRelativePath", "NightSwitchPluginGameModeBase.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ANightSwitchPluginGameModeBase_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ANightSwitchPluginGameModeBase>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ANightSwitchPluginGameModeBase_Statics::ClassParams = {
		&ANightSwitchPluginGameModeBase::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009002ACu,
		METADATA_PARAMS(Z_Construct_UClass_ANightSwitchPluginGameModeBase_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ANightSwitchPluginGameModeBase_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ANightSwitchPluginGameModeBase()
	{
		if (!Z_Registration_Info_UClass_ANightSwitchPluginGameModeBase.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ANightSwitchPluginGameModeBase.OuterSingleton, Z_Construct_UClass_ANightSwitchPluginGameModeBase_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ANightSwitchPluginGameModeBase.OuterSingleton;
	}
	template<> NIGHTSWITCHPLUGIN_API UClass* StaticClass<ANightSwitchPluginGameModeBase>()
	{
		return ANightSwitchPluginGameModeBase::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ANightSwitchPluginGameModeBase);
	ANightSwitchPluginGameModeBase::~ANightSwitchPluginGameModeBase() {}
	struct Z_CompiledInDeferFile_FID_Users_ISILV125_Documents_Unreal_Projects_NightSwitchPlugin_Source_NightSwitchPlugin_NightSwitchPluginGameModeBase_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_ISILV125_Documents_Unreal_Projects_NightSwitchPlugin_Source_NightSwitchPlugin_NightSwitchPluginGameModeBase_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ANightSwitchPluginGameModeBase, ANightSwitchPluginGameModeBase::StaticClass, TEXT("ANightSwitchPluginGameModeBase"), &Z_Registration_Info_UClass_ANightSwitchPluginGameModeBase, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ANightSwitchPluginGameModeBase), 4144582064U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_ISILV125_Documents_Unreal_Projects_NightSwitchPlugin_Source_NightSwitchPlugin_NightSwitchPluginGameModeBase_h_1004242714(TEXT("/Script/NightSwitchPlugin"),
		Z_CompiledInDeferFile_FID_Users_ISILV125_Documents_Unreal_Projects_NightSwitchPlugin_Source_NightSwitchPlugin_NightSwitchPluginGameModeBase_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_ISILV125_Documents_Unreal_Projects_NightSwitchPlugin_Source_NightSwitchPlugin_NightSwitchPluginGameModeBase_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
