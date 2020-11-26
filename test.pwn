#include <a_samp>
#include <YSI_Visual\y_commands>
#include <YSI_Core\y_testing>
#include "inline-objects.inc"

main()
{
    return;
}

public OnGameModeInit()
{
    CreateObject(2921,134.9397,-72.9322,1.4297, 0, 0,0);
    return 1;
}


YCMD:test(playerid, params[], help)
{ 
    if(help) {
        return 0;
    }
    SelectObject(playerid);

    return 1;
}

public OnPlayerSelectObject(playerid, type, objectid, modelid, Float:fX, Float:fY, Float:fZ)
{
    inline Test(pid, playerobject, objid, response, Float:fXx, Float:fYy, Float:fZz, Float:fRotX, Float:fRotY, Float:fRotZ )
    {
        #pragma unused fRotZ, fRotY, fRotX, fZz, fYy, fXx, objid, playerobject, pid
        if(response == EDIT_RESPONSE_FINAL) {
            print("NOINDOINDIOW");
        }
        else if(response == EDIT_RESPONSE_CANCEL)  {
            print("PINOINDIO");
        }
        print("Test");
    }
    EditObjectInline(playerid, objectid, using inline Test);
    return 1;
}


public e_COMMAND_ERRORS:OnPlayerCommandReceived(playerid, cmdtext[], e_COMMAND_ERRORS:success)
{
    
    return COMMAND_OK;
}

public e_COMMAND_ERRORS:OnPlayerCommandPerformed(playerid, cmdtext[], e_COMMAND_ERRORS:success)
{
    
    return COMMAND_OK;
}

public OnPlayerCommandText(playerid, cmdtext[])
{
    return 1;
}