/*
	* Library: Samp Inline Objects (inline-objects.inc)
	* Author: Mergevos
	* Date: 26. Novembre 2020.
	* Copyright: (C) 2020
	* Credits: 
        Y_Less
*/

/**
 * <library name="inline-objects">
 * <section>
 *  Version
 * </section>
 *  1.0.0
 * </library>
 */


// built-in include guard removal
// just in case the user has a local dependency with the same file name
#if defined _inc_async_objects
    #undef _inc_async_objects
#endif
// custom include-guard to ensure we don't duplicate
#if defined _async_objects_included
    #endinput
#endif
#define _async_objects_included

#include <a_samp>

#include <YSI_Coding\y_inline>
#include <YSI_Coding\y_hooks>

static 
    Func: gs_Callback<iiiiiiiiii>;

/**
 * <summary> Edits object inline.</summary>
 * <param name="playerid"> Player who's editing an object.</param>
 * <param name="objectid"> The object which is edited.</param>
 * <param name="func"> Callback/Inline called after.</param>
 * <returns> Return value of EditObject. 1 for succes, 0 for fail.</returns>
 * <seealse name="EditObject"/>
 */

stock EditObjectInline(playerid, objectid, Func: func<iiiiiiiiii>) 
{
    new const ret = EditObject(playerid, objectid);
    if(ret) {
        gs_Callback = func;
        Indirect_Claim(gs_Callback);
    }
    return ret;
}

hook OnPlayerEditObject(playerid, playerobject, objectid, response, Float:fX, Float:fY, Float:fZ, Float:fRotX, Float:fRotY, Float:fRotZ )
{
    // EDIT_RESPONSE_UPDATE seems to get called everytime object is moved.
    // Simply remove it from checking, because it can affect a lot. Indirection may release gs_Callback (eg. callback)
    // early and it does not get claimed again. (Simply: It doesn't get called anymore.)
    @.gs_Callback(playerid, playerobject, objectid, response, fX, fY, fZ, fRotX, fRotY, fRotZ);
    if(response == EDIT_RESPONSE_FINAL || response == EDIT_RESPONSE_CANCEL) {
        Indirect_Release(gs_Callback);
    }
    return 1;
}
