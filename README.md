# 🍀 Bean's DWM
This repository contains my preferred DWM configuration and patches.
## Installation
To install, simply run the premade install script.
```sh
chmod +x ./install-dwm.sh
./install-dwm.sh
```
This will both compile DWM as well as copy the scripts to their respective locations. Make sure that you have `~/.local/bin/` added to your `$PATH` so that the `bar` and `refresh-bar` scripts can be run correctly.
## Patches
Patches are sourced from [here](https://github.com/bakkeby/patches/tree/master/dwm). Many thanks to **bakkeby** for curating such a wonderful little collection of patches.
- Autostart - automatically runs `~/.config/dwm/autostart.sh` on startup, which in turn runs `dwmstatus`
%% - Attach Aside - windows default to being added to the stack rather than being the main window
- Centered Window Name - centers the window name in the status bar
- Cycle Layouts - adds a hotkey to cycle through lots of layouts, rather than being limited to the default of changing to a set one
- Move Center - adds a hotkey to move a floating window to the center of the screen
- Spotify Workaround - allows window rules to apply to Spotify
- Steam - fixes some buggy behaviour with steam
- Vanity Gaps - adds useless gaps between windows
- Warp - moves cursor to currently selected window when moving window focus using hotkeys
## Notable Configuration Changes
- Hotkeys for media keys
- Imports colours from pywal
	- Note that I don't use the urgent borders patch, so this requires the creation of a template for pywal to use that doesn't include the urgent colours
