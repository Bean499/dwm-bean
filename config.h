/* See LICENSE file for copyright and license details. */

/* pywal */
/* no colours are defined in this file because they are imported from pywal cache */
#include "/home/bean/.cache/wal/colors-wal-dwm.h"

/* media keys */
#include <X11/XF86keysym.h>

/* gaps */
static const unsigned int gappih    = 15;       /* horiz inner gap between windows */
static const unsigned int gappiv    = 15;       /* vert inner gap between windows */
static const unsigned int gappoh    = 15;       /* horiz outer gap between windows and screen edge */
static const unsigned int gappov    = 15;       /* vert outer gap between windows and screen edge */
static       int smartgaps          = 0;        /* 1 means no outer gap when there is only one window */
#define FORCE_VSPLIT 1  /* nrowgrid layout: force two clients to always split vertically */
/* gaps file must be imported after setting gaps */
#include "vanitygaps.c"

/* appearance */
static const unsigned int borderpx  = 5;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = { "monospace:size=10" };

/* tagging */
static const char *tags[] = { "I", "II", "III", "IV", "V", "VI", "VII" };
/* static const char *tags[] = { "home", "work", "code", "game", "misc", "musi", "disc" }; */

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Spotify",  		NULL,       NULL,       1 << 5,       0,           0  },
	{ "discord",  		NULL,       NULL,       1 << 6,       0,           0  },
	{ "qutebrowser",  	NULL,       NULL,       1 << 0,       0,           1  },
	{ "mpv",		  	NULL,       NULL,       0,	 	      1,           -1 },
	{ "feh",		  	NULL,       NULL,       0,	 	      1,           -1 },
	{ "Lutris",		  	NULL,       NULL,       0,	 	      1,           -1 },
	{ "Steam",		  	NULL,       NULL,       0,	 	      1,           -1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[T]",      tile },    /* first entry is default */
	{ "[M]",      monocle },
	/* { "[@]",      spiral }, */
	/* { "[\\]",     dwindle }, */
	/* { "D[]",      deck }, */
	/* { "TTT",      bstack }, */
	/* { "===",      bstackhoriz }, */
	/* { "HHH",      grid }, */
	/* { "###",      nrowgrid }, */
	/* { "---",      horizgrid }, */
	/* { ":::",      gaplessgrid }, */
	/* { "|M|",      centeredmaster }, */
	/* { ">M>",      centeredfloatingmaster }, */
	{ "[F]",      NULL },    /* no layout function means floating behavior */
	{ NULL,       NULL },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */

/* dmenu commands - required by source, would love to remove since i don't use dmenu :[
maybe one day i will muster the effort to change the source code so i can remove these */
static char dmenumon[2] = "0"; /* component of dmenucmd in spawn() */
static const char *dmenucmd[] = { "rofi", "-show", "drun", NULL };
static const char *winmenu[] = { "rofi", "-show", "window", NULL };

/* terminal */
static const char *termcmd[]  = { "kitty", NULL };

/* dashboard */
static const char *dashboard[] = { "/home/bean/.config/eww/scripts/open_dashboard.sh", NULL };

/* swap between UK/US keyboard */
static const char *keyboardswap[] = { "/home/bean/.scripts/misc/keyboard.sh", NULL };

/* custom rofi menus */
static const char *musicmenu[] = { "/home/bean/.scripts/rofi/music.sh", NULL };
static const char *screenmenu[] = { "/home/bean/.scripts/rofi/screens.sh", NULL };
static const char *emojimenu[] = { "rofimoji", NULL };

/* colour picker */
static const char *colourpick[] = { "farge", "--notify", NULL };

/* Clear stuff */
static const char *clearnotifs[] 	= { "dunstctl", "close-all", NULL };
static const char *clearwidgets[] 	= { "eww", "close-all", NULL };

/* Volume */
static const char *upvol[]   	= { "pamixer", "-i", "5",     NULL };
static const char *downvol[] 	= { "pamixer", "-d", "5",     NULL };
static const char *mutevol[] 	= { "pamixer", "-t", NULL };

/* Media */
static const char *playpause[]	 	= { "playerctl", "play-pause", NULL };
static const char *next[]			= { "playerctl", "next", NULL };
static const char *prev[]			= { "playerctl", "previous", NULL };
static const char *print[]			= { "scrot", "-e", "mv $f ~/Screenshots/ 2>/dev/null & notify-send --icon=image-missing 'Screenshot taken.'", NULL };

static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_space,  spawn,          {.v = dmenucmd } },
	{ MODKEY,                       XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY,                       XK_d,      spawn,          {.v = dashboard } },
	{ MODKEY,                       XK_p,      spawn,          {.v = screenmenu } },
	{ MODKEY,                       XK_e,      spawn,          {.v = emojimenu } },
	{ MODKEY,                       XK_c,      spawn,          {.v = clearnotifs } },
	{ MODKEY,                       XK_x,      spawn,          {.v = clearwidgets } },
	{ MODKEY|Mod1Mask,              XK_k,      spawn,          {.v = keyboardswap } },
	{ MODKEY|Mod1Mask,              XK_j,      spawn,          {.v = musicmenu } },
	{ MODKEY,                       XK_b,      togglebar,      {0} },

	/* move focus */
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },

	/* grow master */
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },

	/* move window to master */
	{ MODKEY|ShiftMask,             XK_Return, zoom,           {0} },

	/* rofi window mode */
	{ MODKEY,                       XK_Tab,    spawn,          { .v = winmenu } },

	/* kill window */
	{ MODKEY,                       XK_q,      killclient,     {0} },

	/* change layouts */
	{ MODKEY,                       XK_comma,      		setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_period,      	setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_slash,			setlayout,      {.v = &layouts[2]} },

	/* float window */
	{ MODKEY|ControlMask,           XK_space,  togglefloating, {0} },

	/* change tag */
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)

	/* Volume keys */
	{ NULL,							XF86XK_AudioRaiseVolume, 	spawn, {.v = upvol   } },
	{ NULL,							XF86XK_AudioLowerVolume, 	spawn, {.v = downvol } },
	{ NULL,							XF86XK_AudioMute, 			spawn, {.v = mutevol } },

	/* Media keys */
	{ NULL,							XF86XK_AudioPlay, 			spawn, {.v = playpause } },
	{ NULL,							XF86XK_AudioNext, 			spawn, {.v = next } },
	{ NULL,							XF86XK_AudioPrev, 			spawn, {.v = prev } },

	/* Print & colour picker */
	{ NULL,							XK_Print, 	spawn, 		{.v = print } },
	{ MODKEY|Mod1Mask,				XK_c,	 	spawn, 		{.v = colourpick } },

	/* Swap focussed monitor */
	{ MODKEY,                       XK_m,     	focusmon,	{.i = +1 } },

	/* move window to other monitor */
	{ MODKEY|ShiftMask,             XK_m,		tagmon,		{.i = +1 } },

	/* center current floating window */
	{ MODKEY,			           	XK_z,		movecenter,	{0} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

