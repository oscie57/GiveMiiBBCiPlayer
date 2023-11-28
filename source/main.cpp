#include <wups.h>
#include <whb/log.h>
#include <whb/log_module.h>
#include <whb/log_cafe.h>
#include <whb/log_udp.h>
#include <string.h>

#include <coreinit/title.h>

#include <patcher/rplinfo.h>
#include <patcher/patcher.h>

WUPS_PLUGIN_NAME("GiveMiiBBCiPlayer");
WUPS_PLUGIN_DESCRIPTION("Allows the BBC iPlayer app to continue functioning after its discontinuation");
WUPS_PLUGIN_VERSION("v1.0");
WUPS_PLUGIN_AUTHOR("GaryOderNichts, oscie57");
WUPS_PLUGIN_LICENSE("MIT");

#define IPLAYER_CLIENT_ID "a2efa818a34fa16b8afbc8a74eba3eda"
#define IPLAYER_TITLE_ID 0x0005000010154800llu


DECL_FUNCTION(int, AcquireIndependentServiceToken__Q2_2nn3actFPcPCc, uint8_t* token, const char* client_id)
{
    // If this is the BBC iPlayer client, return sucess
    if (client_id && strcmp(client_id, IPLAYER_CLIENT_ID) == 0) {
        WHBLogPrintf("GiveMiiBBCiPlayer: Faking service sucess for '%s'", client_id);
        return 0;
    }

    return real_AcquireIndependentServiceToken__Q2_2nn3actFPcPCc(token, client_id);
}

WUPS_MUST_REPLACE(AcquireIndependentServiceToken__Q2_2nn3actFPcPCc, WUPS_LOADER_LIBRARY_NN_ACT, AcquireIndependentServiceToken__Q2_2nn3actFPcPCc);
