/* ======================================================= # */
/*  _________                _____.__           .__     
    \_   ___ \  ____   _____/ ____\__| ____     |  |__  
    /    \  \/ /  _ \ /    \   __\|  |/ ___\    |  |  \ 
    \     \___(  <_> )   |  \  |  |  / /_/  >   |   Y  \
     \______  /\____/|___|  /__|  |__\___  / /\ |___|  /
            \/            \/        /_____/  \/      \/  */
/* ========================================================== # */
/* Appearance */
static const unsigned int borderpx   = 0; // Border size in pixels
static const unsigned int gappx      = 4; // Gap size in pixels
static const unsigned int snap       = 4; // Distance for window to snap
static const int showbar             = 1; // 1:show, 0:no bar
static const int topbar              = 1; // 0 for bottom, 1 for top
static const char *fonts[]           = { "Agave:size=15", "monospace:size=13" }; // Mainly for the bar
static const char dmenufont[]        = { "monospace:size=10" }; // Dmenu
// Color select zone
static const char none[]             = "#000000"; // Placeholder for no color
static const char dark_background[]  = "#1b1b29";
static const char dark_purple[]      = "#4b26ab";
static const char dark_gray[]        = "#2a1f47";
static const char med_gray[]         = "#2C2A4A";
static const char med_purple[]       = "#7C72A0";
static const char light_purple3[]    = "#BC96E6";
static const char med_blue[]         = "#14213D";
static const char light_pink[]       = "#ff79c6";
static const char light_foreground[] = "#BFAAE3";
static const char pink_foreground[]  = "#8F3985";
static const char light_gray[]       = "#2F2F4a";
static const char light_purple2[]    = "#A882DD";
static const char light_purple[]     = "#6546e0";
static const char light_purpleblue[] = "#8897F4";
static const char *colors[][3]       = {
	/* scheme               fg            bg          border   */
	[SchemeNorm]     = { light_foreground, dark_background, light_gray        },
	[SchemeSel]      = { light_foreground, light_gray,      light_purpleblue  },
	[SchemeStatus]   = { light_purple3,    dark_background, none              }, // Statusbar right
	[SchemeTagsSel]  = { light_pink,       light_gray,      none              }, // Tagbar left selected
    [SchemeTagsNorm] = { light_purple3,    dark_background, none              }, // Tagbar left unselected
    [SchemeInfoSel]  = { light_pink,       light_gray,      none              }, // infobar middle  selected
    [SchemeInfoNorm] = { light_foreground, dark_background, none              }, // infobar middle  unselected
};

// Tag naming
static const char *tags[] = { "一", "二", "三", "四", "五", "六", "七", "八", "九" };

// Set window rules
static const Rule rules[] = {
	/* class      instance    title       tags mask     iscentered   isfloating   monitor  float(x,y,w,h) floatbrd scratchkey */
    { "kitty",    NULL,       NULL,       0,            1,           0,           -1,      50,50,800,400,     5,     0  },
    { NULL,       NULL,   "scratchpad",   0,            1,           1,           -1,      50,50,800,400,     5,    's' },
    { NULL,       NULL,   "scratchpad2",  0,            0,           1,           -1,      50,50,900,400,     5,    'v' },
    { NULL,       NULL,   "scratchpad3",  0,            0,           1,           -1,      650,0,600,350,     3,    'm' },
};

static const float mfact     = 0.50; // Size of master area
static const int nmaster     = 1;    // Number of windows in master
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */

// Layout options
static const Layout layouts[] = {
	/* symbol    layout */
	{ " ",      tile },    // Symbol for default tiling layout
	{ " ",      NULL },    // Symbol for floating layout
	{ " ",      monocle }, // Symbol for monocle layout
};

// Key definitions 
#define MODKEY Mod1Mask // Mod1Mask: altkey; Mod4Mask: super key
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

// Shell spawning helper
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

// Commands
static char dmenumon[2] = "0"; // component of dmenucmd, manipulated in spawn()
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", dark_background, "-nf", light_foreground, "-sb", light_gray, "-sf", light_foreground, NULL }; // Basic dmenu configuration
static const char *termcmd[]  = { "kitty", NULL }; // Set your preferred terminal here

// Named scratchpad commands
//                     cmdname         key  program settitle  title         command 
static const char *scratchpadcmd[]  = {"s", "kitty", "-T", "scratchpad",     NULL  }; 
static const char *scratchpadcmd2[] = {"v", "kitty", "-T", "scratchpad2", "vifmrun"}; 
static const char *scratchpadcmd3[] = {"m", "kitty", "-T", "scratchpad3", "ncmpcpp"}; 

#include "selfrestart.c"
#include "movestack.c"
// Keybinds
static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_p,      spawn,          {.v = dmenucmd } }, // Dmenu
	{ MODKEY,                       XK_Return, spawn,          {.v = termcmd } },  // Open terminal
	{ MODKEY,                       XK_grave,  togglescratch,  {.v = scratchpadcmd  } }, // Open scratchpad 's'
	{ MODKEY|ShiftMask,             XK_grave,  togglescratch,  {.v = scratchpadcmd2 } }, // Open scratchpad 'v'
	{ MODKEY|ControlMask,           XK_m,      togglescratch,  {.v = scratchpadcmd3 } }, // Open scratchpad 'm'
	{ MODKEY,                       XK_b,      togglebar,      {0} }, // Toggles statusbar
	{ MODKEY,                       XK_r,      rotatestack,    {.i = +1 } }, // Rotates windows around the stack (Up)
	{ MODKEY|ShiftMask,             XK_r,      rotatestack,    {.i = -1 } }, // Rotates windows around the stack (Down)
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } }, // Shift window focus up stack
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } }, // Shift window focus down stack
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } }, // Increase count of master area
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } }, // Decrease count of master area
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} }, // Set master size right
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} }, // Set master size left
	{ MODKEY|ShiftMask,             XK_j,      movestack,      {.i = +1 } }, // Moves focused window up stack
	{ MODKEY|ShiftMask,             XK_k,      movestack,      {.i = -1 } }, // Moves focused window down stack
	{ MODKEY,                       XK_Tab,    view,           {0} }, // Swaps to last focused tag
	{ MODKEY|ShiftMask,             XK_c,      killclient,     {0} }, // Kills focused window
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} }, // Sets tag in tiled mode
	{ MODKEY|ShiftMask,             XK_f,      setlayout,      {.v = &layouts[1]} }, // Sets tag in floating mode
    { MODKEY,                       XK_f,      fullscreen,     {0} }, // Sets current window as fullscreen
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} }, // Sets tag in monocle mode
	{ MODKEY|ControlMask|ShiftMask, XK_f,      togglefloating, {0} }, // Toggles floating on focused window
	{ MODKEY,                       XK_s,      togglesticky,   {0} }, // Toggles sticky on focued window
   	{ MODKEY,		            	XK_Insert,	spawn,	       SHCMD("notify-send \" : \" \"$(xclip -o -selection clipboard)\"") }, // Prints clipboard to a notification
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } }, // Displays all tags at once
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } }, // Makes all tags active
	{ MODKEY,                       XK_comma,  focusmon,       {.i = 0 } }, // Focus first mon
	{ MODKEY,                       XK_period, focusmon,       {.i = 1 } }, // Focus second mon
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = 0 } }, // Sends focused window to first mon
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = 1 } }, // Sends focused window to second mon
	TAGKEYS(                        XK_1,                      0) // Focus tag #1
	TAGKEYS(                        XK_2,                      1) // Focus tag #2
	TAGKEYS(                        XK_3,                      2) // Focus tag #3
	TAGKEYS(                        XK_4,                      3) // Focus tag #4
	TAGKEYS(                        XK_5,                      4) // Focus tag #5
	TAGKEYS(                        XK_6,                      5) // Focus tag #6
	TAGKEYS(                        XK_7,                      6) // Focus tag #7
	TAGKEYS(                        XK_8,                      7) // Focus tag #8
	TAGKEYS(                        XK_9,                      8) // Focus tag #9
    { MODKEY|ShiftMask,             XK_r,      self_restart,   {0} }, // Restart dwm without quit
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} }, // Quit dwm
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} }, 
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
  	{ ClkStatusText,        0,              Button1,        sigdwmblocks,   {.i = 1} }, // Left Click
	{ ClkStatusText,        0,              Button2,        sigdwmblocks,   {.i = 2} }, // Middle Click
	{ ClkStatusText,        0,              Button3,        sigdwmblocks,   {.i = 3} }, // Right Click
	{ ClkStatusText,        0,              Button4,        sigdwmblocks,   {.i = 4} }, // Scroll Down
	{ ClkStatusText,        0,              Button5,        sigdwmblocks,   {.i = 5} }, // Scroll Up
	{ ClkStatusText,        ShiftMask,      Button1,        sigdwmblocks,   {.i = 6} }, // Shift + Click
	{ ClkStatusText,        ShiftMask,      Button2,        sigdwmblocks,   {.i = 7} }, // Shift + Middle Click
	{ ClkStatusText,        ShiftMask,      Button4,        sigdwmblocks,   {.i = 8} }, // Shift + Scroll Down
	{ ClkStatusText,        ShiftMask,      Button5,        sigdwmblocks,   {.i = 9} }, // Shift + Scroll Up
	{ ClkStatusText,        ShiftMask,      Button3,        spawn,          SHCMD("kitty nvim ~/dwm/dwmblocks/config.h") }, // Shift + Right Click
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY|ShiftMask,Button1,       movemouse,      {.i = 1} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkClientWin,         MODKEY|ShiftMask,Button3,       resizemouse,    {.i = 1} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};
