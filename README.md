# 🍀 Bean's DWM
This repository contains my preferred DWM configuration and patches.
## Installation
To install, simply run the premade install script.
```sh
chmod +x ./install.sh
./install.sh
```
You will also want to move `autostart.sh` and `dwmstatus.sh` into `~/.config/dwm`:
```sh
cp ./autostart.sh ~/.config/dwm/autostart.sh
cp ./dwmstatus.sh ~/.config/dwm/dwmstatus.sh
```
## Patches
Patches are sourced from [here](https://github.com/bakkeby/patches/tree/master/dwm). Many thanks to **bakkeby** for curating such a wonderful little collection of patches.
- Autostart - automatically runs `~/.config/dwm/autostart.sh` on startup, which in turn runs `~/.config/dwm/dwmstatus.sh`
- Centered Window Name - centers the window name in the status bar
- Move Center - adds a hotkey to move a floating window to the center of the screen
- Spotify Workaround - allows window rules to apply to Spotify
- Steam - fixes some buggy behaviour with steam
- Vanity Gaps - adds useless gaps between windows
- Warp - moves cursor to currently selected window when moving window focus using hotkeys
## Notable Configuration Changes
- Hotkeys for media keys
- Imports colours from pywal
	- Note that I don't use the urgent borders patch, so this requires the creation of a template for pywal to use that doesn't include the urgent colours
