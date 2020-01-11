/*
(C) Gérald Döserich
*/

#include <a_samp>
#define VoiceVersion 0.9

#define VOICE_ERROR_OK							 1
#define VOICE_ERROR_SERVER_INACTIVE				-1
#define VOICE_ERROR_PLAYER_NOT_CONNECTED		-2
#define VOICE_ERROR_INVALID_PARAMETER_LENGTH	-3

#define VOICE_INVALID_PLAYERID					65535
#define VOICE_INVALID_TOWERID					65534
#define VOICE_INVALID_RADIOID					65533

// Server
native Voice_Init(port, Debug = false);
// Wait until the server is ready to accept connections
native Voice_WaitForStart();
native Voice_Quit();
native Voice_SetVoiceDistance(distance);
native Voice_EnableRadio();
native Voice_DisableRadio();

// Player
native Voice_IsVoiceConnected(playerid);
native Voice_SetPlayerMuted(playerid);
native Voice_SetPlayerUnmuted(playerid);
native Voice_SetPlayerRadioChannel(playerid, channel);
native Voice_SetPlayerRadioEnabled(playerid);
native Voice_SetPlayerRadioDisabled(playerid);
native Voice_SetPlayerRadioDevice(playerid, radioId);
// Modifier between 0 and 100
native Voice_GetPlayerVolumeModifier(playerid);
native Voice_SetPlayerVolumeModifier(playerid, modifier);
// A "talk" is basically just simulating that the persons are next to each other (phone calls)
native Voice_StartPlayerTalkWith(playerid, otherPlayerId);
native Voice_EndPlayerTalkWith(playerid, otherPlayerId);

native Voice_CreateRadioTower(Float:x,Float:y,Float:z, Float:radius);
native Voice_SetRadioTowerPosition(towerid, Float:x, Float:y, Float:z);
native Voice_SetRadioTowerRange(towerid, Float:radius);
native Voice_SetRadioTowerEnabled(towerid);
native Voice_SetRadioTowerDisabled(towerid);
native Voice_DeleteRadioTower(towerid);

native Voice_CreateRadioDevice(Float:maxRange);
native Voice_SetRadioDeviceRange(deviceid, Float:maxRange);
native Voice_DeleteRadioDevice(deviceid);

native Voice_DebugSimulateRadio(playerid, bool:enabled);

native Voice_UpdateVirtualWorld(playerid, worldid);

// Only if muted server side (SetPlayerMuted/SetPlayerUnmuted)
forward OnPlayerMuted(playerid, bool:isMuted);
forward OnRadioChannelChanged(playerid, newChannel, oldChannel);
forward OnPlayerStartedTalking(playerid);
forward OnPlayerStoppedTalking(playerid);

forward OnTeamSpeakConnected(playerid);
forward OnTeamSpeakDisconnected(playerid);

//Hooking Virtual Worlds
native __SetPlayerVirtualWorld(playerid,worldid) = SetPlayerVirtualWorld;
stock _SetPlayerVirtualWorld(playerid,worldid)
{
	Voice_UpdateVirtualWorld(playerid, worldid);
	__SetPlayerVirtualWorld(playerid,worldid);
	return 1;
}
#if defined _ALS_SetPlayerVirtualWorld
	#undef SetPlayerVirtualWorld
#else
	#define _ALS_SetPlayerVirtualWorld
#endif
#define SetPlayerVirtualWorld _SetPlayerVirtualWorld


