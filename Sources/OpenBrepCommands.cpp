#include "OpenBrepCommands.hpp"
#include "AddOnVersion.hpp"

#include <chrono>
#include <cstdlib>
#include <thread>

namespace {

static void LaunchOpenBrepInBrowser ()
{
	std::system ("open http://localhost:8501");
}

static void LaunchGdlCopilot ()
{
	std::system ("cd ~/MAC工作/工作/code/开源项目/openbrep-addon && python -m uvicorn copilot.server:app --port 8502 &");
	std::this_thread::sleep_for (std::chrono::milliseconds (1500));
	std::system ("open http://localhost:8502");
}

} // namespace

GSErrCode OpenBrepMenuCommandHandler (const API_MenuParams* menuParams)
{
	if (menuParams->menuItemRef.menuResID != OpenBrepMenuResId)
		return NoError;

	if (menuParams->menuItemRef.itemIndex == OpenBrepMenuItemLaunchOpenBrepIndex) {
		LaunchOpenBrepInBrowser ();
	} else if (menuParams->menuItemRef.itemIndex == OpenBrepMenuItemGdlCopilotIndex) {
		LaunchGdlCopilot ();
	}

	return NoError;
}

