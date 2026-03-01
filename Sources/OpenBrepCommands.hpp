#pragma once

#include "APIEnvir.h"
#include "ACAPinc.h"

constexpr short OpenBrepMenuResId = 32500;
constexpr short OpenBrepMenuItemLaunchOpenBrepIndex = 1;
constexpr short OpenBrepMenuItemGdlCopilotIndex = 2;

GSErrCode OpenBrepMenuCommandHandler (const API_MenuParams* menuParams);
