#pragma once

#include "PluginBase/Modules.h"
#include "PluginBase/HookManager.h"

#include <convar.h>

#include <optional>

class TextureTools : public Module<TextureTools>
{
public:
	TextureTools();

	static bool CheckDependencies();

private:
	Hook<HookFunc::CBaseClientRenderTargets_InitClientRenderTargets> m_CreateRenderTargetsHook;

	void ToggleFullResRTs();
	void InitClientRenderTargetsOverride(CBaseClientRenderTargets* pThis, IMaterialSystem* pMaterialSystem, IMaterialSystemHardwareConfig* config, int waterRes, int cameraRes);

	ConVar ce_texturetools_full_res_rts;
};
