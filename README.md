# SAMP Voice

> SAMP Voice is no longer in active development
> I may or may not release updates

# Description
SAMP Voice is an experimental Voice chat for SA-MP. Features include:
 - Real time communication with other players
 - Talk to remote players over Radio
 - Voice over radio is altered
 - Radio towers
 - Scriptable over PAWN

# Requirements
- An additional UDP/IP port. The port from the SA-MP Server cannot be used
- [Visual C++ Redistributable für Visual Studio 2015](https://www.microsoft.com/de-ch/download/details.aspx?id=48145) for Windows
- libstdc\++6 for linux (sudo apt-get install libstdc++6)
- TeamSpeak Server
- TeamSpeak Client

# Installation
- Download the plugin from the release page
- Add the plugin to the Plugins directory of the Server
- Add the plugin to the server.cfg
- Add the include to the includes directory
- The plugin should now be loaded upon server start
    - Loading the plugin does not actually initiate a server
- Go to Setup a server

# Setup a server
This is minimal configuration needed to run SAMP Voice
## Setup PAWN
### OnGameModeInit
The following lines initialize the voice server on port 5555 in debug mode. Change the 'true' to 'false' to disable debug mode.
Then the server waits until SAMP Voice is ready to accept connections.
```c
Voice_Init(5555, true);
Voice_WaitForStart(); // Wait until the server has fully loaded
```
### OnGameModeExit
The following lines are not required but recommended for a graceful shutdown
```c
Voice_Quit();
```
The SAMP Server has now been setup.
## TeamSpeak Server
1. Download and install the TeamSpeak Plugin (see release page)
2. Create a dedicated channel for "In-Game Chat"
3. Add the following lines somewhere in the channel description:
```
[VOICE-INFO-START]
<SERVER-IP>:<SAMP VOICE PORT>
[VOICE-INFO-END]
```
For example:
```
[VOICE-INFO-START]
127.0.0.1:5555
[VOICE-INFO-END]
```
4. Make sure your player name in SA-MP and in TeamSpeak match
5. Make sure the plugin is loaded in TeamSpeak
6. Join the created channel. A connection should now be established to the server (enable debug mode in SAMP Voice Plugin to verify)
7. If your player name matches then your are now successfully able to use SAMP Voice
 
# Test Gamemode
See release page for a test gamemode with all functions.
