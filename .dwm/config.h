/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx       = 2;   /* border pixel of windows */
static const unsigned int snap           = 32;  /* snap pixel */
static const int scalepreview            = 4;        /* Tag preview scaling */
static const unsigned int gappih         = 10;  /* horiz inner gap between windows */
static const unsigned int gappiv         = 10;  /* vert inner gap between windows */
static const unsigned int gappoh         = 10;  /* horiz outer gap between windows and screen edge */
static const unsigned int gappov         = 10;  /* vert outer gap between windows and screen edge */
static const int smartgaps_fact          = 1;   /* gap factor when there is only one client; 0 = no gaps, 3 = 3x outer gaps */
static const int showbar                 = 1;   /* 0 means no bar */
static const int topbar                  = 1;   /* 0 means bottom bar */
/* Status is to be shown on: -1 (all monitors), 0 (a specific monitor by index), 'A' (active monitor) */
static const int statusmon               = -1;
static const unsigned int systrayspacing = 2;   /* systray spacing */
static const int showsystray             = 1;   /* 0 means no systray */

/* Indicators: see patch/bar_indicators.h for options */
static int tagindicatortype              = INDICATOR_BOTTOM_BAR; 
static int tiledindicatortype            = INDICATOR_NONE;
static int floatindicatortype            = INDICATOR_TOP_LEFT_SQUARE;
static const char *fonts[]               = {
			"JetBrainsMonoNL NFP:size=11:style=Bold", 
  			"Font Awesome 6 Free Solid:size=11"
};
static const char dmenufont[]            = "JetBrainsMonoNL NFP:size=11:style=Bold";

static char c000000[]                    = "#000000"; // placeholder value

static char normfgcolor[]                = "#bbbbbb";
static char normbgcolor[]                = "#222222";
static char normbordercolor[]            = "#444444";
static char normfloatcolor[]             = "#db8fd9";

static char selfgcolor[]                 = "#eeeeee";
static char selbgcolor[]                 = "#005577";
static char selbordercolor[]             = "#005577";
static char selfloatcolor[]              = "#005577";

static char titlenormfgcolor[]           = "#bbbbbb";
static char titlenormbgcolor[]           = "#222222";
static char titlenormbordercolor[]       = "#444444";
static char titlenormfloatcolor[]        = "#db8fd9";

static char titleselfgcolor[]            = "#eeeeee";
static char titleselbgcolor[]            = "#005577";
static char titleselbordercolor[]        = "#005577";
static char titleselfloatcolor[]         = "#005577";

static char tagsnormfgcolor[]            = "#bbbbbb";
static char tagsnormbgcolor[]            = "#222222";
static char tagsnormbordercolor[]        = "#444444";
static char tagsnormfloatcolor[]         = "#db8fd9";

static char tagsselfgcolor[]             = "#eeeeee";
static char tagsselbgcolor[]             = "#005577";
static char tagsselbordercolor[]         = "#005577";
static char tagsselfloatcolor[]          = "#005577";

static char hidnormfgcolor[]             = "#005577";
static char hidselfgcolor[]              = "#227799";
static char hidnormbgcolor[]             = "#222222";
static char hidselbgcolor[]              = "#222222";

static char urgfgcolor[]                 = "#bbbbbb";
static char urgbgcolor[]                 = "#222222";
static char urgbordercolor[]             = "#ff0000";
static char urgfloatcolor[]              = "#db8fd9";

static const unsigned int baralpha = 0xd0;
static const unsigned int borderalpha = OPAQUE;
static const unsigned int alphas[][3] = {
	/*                       fg      bg        border     */
	[SchemeNorm]         = { OPAQUE, baralpha, borderalpha },
	[SchemeSel]          = { OPAQUE, baralpha, borderalpha },
	[SchemeTitleNorm]    = { OPAQUE, baralpha, borderalpha },
	[SchemeTitleSel]     = { OPAQUE, baralpha, borderalpha },
	[SchemeTagsNorm]     = { OPAQUE, baralpha, borderalpha },
	[SchemeTagsSel]      = { OPAQUE, baralpha, borderalpha },
	[SchemeHidNorm]      = { OPAQUE, baralpha, borderalpha },
	[SchemeHidSel]       = { OPAQUE, baralpha, borderalpha },
	[SchemeUrg]          = { OPAQUE, baralpha, borderalpha },
};

static char *colors[][ColCount] = {
	/*                       fg                bg                border                float */
	[SchemeNorm]         = { normfgcolor,      normbgcolor,      normbordercolor,      normfloatcolor },
	[SchemeSel]          = { selfgcolor,       selbgcolor,       selbordercolor,       selfloatcolor },
	[SchemeTitleNorm]    = { titlenormfgcolor, titlenormbgcolor, titlenormbordercolor, titlenormfloatcolor },
	[SchemeTitleSel]     = { titleselfgcolor,  titleselbgcolor,  titleselbordercolor,  titleselfloatcolor },
	[SchemeTagsNorm]     = { tagsnormfgcolor,  tagsnormbgcolor,  tagsnormbordercolor,  tagsnormfloatcolor },
	[SchemeTagsSel]      = { tagsselfgcolor,   tagsselbgcolor,   tagsselbordercolor,   tagsselfloatcolor },
	[SchemeHidNorm]      = { hidnormfgcolor,   hidnormbgcolor,   c000000,              c000000 },
	[SchemeHidSel]       = { hidselfgcolor,    hidselbgcolor,    c000000,              c000000 },
	[SchemeUrg]          = { urgfgcolor,       urgbgcolor,       urgbordercolor,       urgfloatcolor },
};

/* Tags
 * In a traditional dwm the number of tags in use can be changed simply by changing the number
 * of strings in the tags array. This build does things a bit different which has some added
 * benefits. If you need to change the number of tags here then change the NUMTAGS macro in dwm.c.
 *
 * Examples:
 *
 *  1) static char *tagicons[][NUMTAGS*2] = {
 *         [DEFAULT_TAGS] = { "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "E", "F", "G", "H", "I" },
 *     }
 *
 *  2) static char *tagicons[][1] = {
 *         [DEFAULT_TAGS] = { "•" },
 *     }
 *
 * The first example would result in the tags on the first monitor to be 1 through 9, while the
 * tags for the second monitor would be named A through I. A third monitor would start again at
 * 1 through 9 while the tags on a fourth monitor would also be named A through I. Note the tags
 * count of NUMTAGS*2 in the array initialiser which defines how many tag text / icon exists in
 * the array. This can be changed to *3 to add separate icons for a third monitor.
 *
 * For the second example each tag would be represented as a bullet point. Both cases work the
 * same from a technical standpoint - the icon index is derived from the tag index and the monitor
 * index. If the icon index is is greater than the number of tag icons then it will wrap around
 * until it an icon matches. Similarly if there are two tag icons then it would alternate between
 * them. This works seamlessly with alternative tags and alttagsdecoration patches.
 */
static char *tagicons[][NUMTAGS] =
{
	[DEFAULT_TAGS]        = { "", "", "󰈹", "", "", "", "", "", "" },
	[ALTERNATIVE_TAGS]    = { "A", "B", "C", "D", "E", "F", "G", "H", "I" },
	[ALT_TAGS_DECORATION] = { "<1>", "<2>", "<3>", "<4>", "<5>", "<6>", "<7>", "<8>", "<9>" },
};
/* "󰈹" "󰖟" "" "" "" "" */

/* There are two options when it comes to per-client rules:
 *  - a typical struct table or
 *  - using the RULE macro
 *
 * A traditional struct table looks like this:
 *    // class      instance  title  wintype  tags mask  isfloating  monitor
 *    { "Gimp",     NULL,     NULL,  NULL,    1 << 4,    0,          -1 },
 *    { "Firefox",  NULL,     NULL,  NULL,    1 << 7,    0,          -1 },
 *
 * The RULE macro has the default values set for each field allowing you to only
 * specify the values that are relevant for your rule, e.g.
 *
 *    RULE(.class = "Gimp", .tags = 1 << 4)
 *    RULE(.class = "Firefox", .tags = 1 << 7)
 *
 * Refer to the Rule struct definition for the list of available fields depending on
 * the patches you enable.
 */
static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 *	WM_WINDOW_ROLE(STRING) = role
	 *	_NET_WM_WINDOW_TYPE(ATOM) = wintype
	 */
	RULE(.wintype = WTYPE "DIALOG", .isfloating = 1)
	RULE(.wintype = WTYPE "UTILITY", .isfloating = 1)
	RULE(.wintype = WTYPE "TOOLBAR", .isfloating = 1)
	RULE(.class = "gimp", .tags = 1 << 1)			/* определение правила открытия программы Gimp 1 окно на теге 2 */
	RULE(.class = "firefox", .tags = 1 << 2)
	RULE(.class = "thunderbird", .tags = 1 << 3)
	RULE(.class = "TelegramDesktop", .tags = 1 << 7)
	RULE(.class = "Whatsapp-for-linux", .tags = 1 << 6)
	RULE(.class = "whatsapp-desktop", .tags = 1 << 6) 
	RULE(.class = "WhatSie", .tags = 1 << 6)
	RULE(.class = "discord", .tags = 1 << 8)
	RULE(.class = "steam", .tags = 1 << 5)
	RULE(.class = "obs", .tags = 1 << 4)
	RULE(.class = "Cherrytree", .tags = 1 << 1)
	RULE(.class = "Yandex-browser", .tags = 1 << 2)
	RULE(.class = "kitty", .tags = 1 << 0)
	RULE(.class = "Alacritty", .tags = 1 << 0)
	RULE(.class = "Pcmanfm", .tags = 1 << 1)
	RULE(.class = "strawberry", .tags = 1 << 4)
	RULE(.class = "Subl", .tags = 1 << 1)
	RULE(.class = "StartWine", .tags = 1 << 5)

};

/* Bar rules allow you to configure what is shown where on the bar, as well as
 * introducing your own bar modules.
 *
 *    monitor:
 *      -1  show on all monitors
 *       0  show on monitor 0
 *      'A' show on active monitor (i.e. focused / selected) (or just -1 for active?)
 *    bar - bar index, 0 is default, 1 is extrabar
 *    alignment - how the module is aligned compared to other modules
 *    widthfunc, drawfunc, clickfunc - providing bar module width, draw and click functions
 *    name - does nothing, intended for visual clue and for logging / debugging
 */
static const BarRule barrules[] = {
	/* monitor   bar    alignment         widthfunc                 drawfunc                clickfunc                hoverfunc                name */
	{ -1,        0,     BAR_ALIGN_LEFT,   width_tags,               draw_tags,              click_tags,              hover_tags,              "tags" },
	{  0,        0,     BAR_ALIGN_RIGHT,  width_systray,            draw_systray,           click_systray,           NULL,                    "systray" },
	{ -1,        0,     BAR_ALIGN_LEFT,   width_ltsymbol,           draw_ltsymbol,          click_ltsymbol,          NULL,                    "layout" },
	{ statusmon, 0,     BAR_ALIGN_RIGHT,  width_status,             draw_status,            click_status,            NULL,                    "status" },
	{ -1,        0,     BAR_ALIGN_NONE,   width_wintitle,           draw_wintitle,          click_wintitle,          NULL,                    "wintitle" },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "┇ ",      tile },    /* first entry is default */
	{ "┇ ",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
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
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = {
	"dmenu_run",
	"-m", dmenumon,
	"-fn", dmenufont,
	"-nb", normbgcolor,
	"-nf", normfgcolor,
	"-sb", selbgcolor,
	"-sf", selfgcolor,
	NULL
};
static const char *termcmd[]  = { "kitty", NULL };

/* Команда для получения скриншота и остальных моих программ */
static const char *flameshot[] = { "flameshot", "gui", NULL };
static const char *bpytopcmd[]  = { "kitty", "-e", "bpytop", NULL };
static const char *neovim[]  = { "kitty", "-e", "nvim", NULL };
static const char *firefoxcmd[]  = { "firefox", NULL };
static const char *yandexb[]  = { "yandex-browser-stable", NULL };
static const char *telegram[] =  { "telegram-desktop", NULL };
static const char *discord[] =     { "discord", NULL };
static const char *Rofi[] =     { "rofi", "run", "-show", "drun", "-show-icons", NULL };
static const char *bettcmd[] = { "betterlockscreen", "-l", "dim", NULL };
static const char *obs[] = { "obs", NULL };
static const char *thunderbird[] = { "thunderbird", NULL };
static const char *steam[] = { "steam", NULL };

static const Key keys[] = {
	/* модификатор                  клавиша        функция                  аргумент */
	/* мои привязки */

#include <X11/XF86keysym.h>
#define XF86XK_AudioLowerVolume 0x1008FF11   /* Volume control down        */
#define XF86XK_AudioMute        0x1008FF12   /* Mute sound from the system */
#define XF86XK_AudioRaiseVolume 0x1008FF13   /* Volume control up          */

// Управление громкостью

/*	{ 0,                            XF86XK_AudioMute,    		spawn,          SHCMD("pactl set-sink-mute 0 toggle && dunstvol") }, */
/*      { 0,                            XF86XK_AudioLowerVolume,        spawn,          SHCMD("pactl set-sink-volume 0 -5% && dunstvol") }, */
/*      { 0,                            XF86XK_AudioRaiseVolume,        spawn,          SHCMD("pactl set-sink-volume 0 +5% && dunstvol") }, */
	{ 0,                            XF86XK_AudioMute,               spawn,          SHCMD("pactl set-sink-mute 0 toggle && pkill -RTMIN+1 dwmblocks") }, 
	{ 0,                            XF86XK_AudioLowerVolume,	 spawn,          SHCMD("pactl set-sink-volume 0 -5% && pkill -RTMIN+1 dwmblocks") },
        { 0,                            XF86XK_AudioRaiseVolume,	 spawn,          SHCMD("pactl set-sink-volume 0 +5% && pkill -RTMIN+1 dwmblocks") },

// Назначения клавиш в разные дистрибутивы

	{ 0,                            XK_Print,			spawn,		{.v = flameshot } },
	{ MODKEY,                       XK_Escape,			spawn,          {.v = bpytopcmd } },
	{ MODKEY|ShiftMask,             XK_v,				spawn,          {.v = neovim } },
	{ MODKEY|ShiftMask,             0x6cd,				spawn,          {.v = neovim } },
	{ MODKEY|ShiftMask,		XK_f,				spawn,		{.v = firefoxcmd } },
	{ 0,             		XF86XK_HomePage,    		spawn,          {.v = firefoxcmd } },
	{ MODKEY|ShiftMask,             XK_y,                          	spawn,          {.v = yandexb } },
	{ MODKEY|ShiftMask,             0x6ce,                          spawn,          {.v = yandexb } },
	{ MODKEY|ShiftMask,             0x6c1,				spawn,          {.v = firefoxcmd } },
	{ MODKEY|ShiftMask,             XK_t,				spawn,          {.v = telegram } }, /* запуск telegram */
	{ MODKEY|ShiftMask,             0x6c5,				spawn,          {.v = telegram } }, /* запуск telegram */
/*	{ MODKEY|ShiftMask,             XK_s,				spawn,          SHCMD("'/home/freedomsky/.local/bin/steam-runtime' %U") }, /* запуск steam */
/*	{ MODKEY|ShiftMask,             0x6d9,				spawn,          SHCMD("'/home/freedomsky/.local/bin/steam-runtime' %U") }, /* запуск steam */
	{ MODKEY|ShiftMask,             XK_s,				spawn,          {.v = steam } }, /* запуск steam */
	{ MODKEY|ShiftMask,             0x6d9,				spawn,          {.v = steam } }, /* запуск steam */
        { MODKEY,		        XK_s,                           spawn,          SHCMD("/usr/bin/startwine") }, /* запуск StartWine */
        { MODKEY,             		0x6d9,                          spawn,          SHCMD("/usr/bin/startwine") }, /* запуск StartWine */
	{ MODKEY|ShiftMask,             XK_d,				spawn,		{.v = discord} },
	{ MODKEY|ShiftMask,             0x6d7,				spawn,		{.v = discord} },
/*	{ MODKEY|ShiftMask,             XK_d,				spawn,          SHCMD(discord-screenaudio) }, */
/*	{ MODKEY|ShiftMask,             0x6d7,				spawn,          SHCMD(discord-screenaudio) }, */
/*	{ MODKEY|ShiftMask,             XK_w,				spawn,          SHCMD("/opt/whatsapp-desktop/WhatsApp") }, /* для Gentoo */
/*	{ MODKEY|ShiftMask,             0x6c3,				spawn,          SHCMD("/opt/whatsapp-desktop/WhatsApp") }, /* для Gentoo */
/*	{ MODKEY|ShiftMask,             XK_w,                           spawn,          SHCMD("whatsapp-for-linux") }, /* Для остальных */
/*  	{ MODKEY|ShiftMask,             0x6c3,                          spawn,          SHCMD("whatsapp-for-linux") }, /* Для остальных */
	{ MODKEY|ShiftMask,             XK_w,                           spawn,          SHCMD("whatsie") }, /* Клиент ватсапп */
	{ MODKEY|ShiftMask,             0x6c3,                          spawn,          SHCMD("whatsie") }, /* Клиент ватсапп */
/*	{ MODKEY|ShiftMask,             XK_o,				spawn,          {.v = obs } }, */
/*	{ MODKEY|ShiftMask,             0x6dd,				spawn,          {.v = obs } }, */
	{ MODKEY|ShiftMask,             XK_m,				spawn,          {.v = thunderbird } },
	{ MODKEY|ShiftMask,             0x6d8,				spawn,          {.v = thunderbird } },
	{ 0,			        XF86XK_Mail,			spawn,          {.v = thunderbird } },
	{ MODKEY|ShiftMask,             XK_g,				spawn,		SHCMD("gimp") },
	{ MODKEY|ShiftMask,             0x6d0,				spawn,		SHCMD("gimp") },
	{ MODKEY|ShiftMask,             XK_p,				spawn,          SHCMD("pcmanfm") },
	{ MODKEY|ShiftMask,             0x6da,				spawn,          SHCMD("pcmanfm") },
	{ MODKEY|ShiftMask,             XK_c,         			spawn,		SHCMD("cherrytree") },
	{ MODKEY|ShiftMask,             0x6d3,        			spawn,         	SHCMD("cherrytree") },
	{ MODKEY|ShiftMask,             XK_k,        			spawn,		SHCMD("setxkbmap -model pc105 -layout us,ru -option grp:alt_shift_toggle") },
	{ MODKEY|ShiftMask,             0x6cc,        			spawn,		SHCMD("setxkbmap -model pc105 -layout us,ru -option grp:alt_shift_toggle") },
	{MODKEY|ControlMask,            XK_s,         			spawn,		SHCMD("shutdown -h now") },
	{MODKEY|ControlMask,            0x6d9,        			spawn,		SHCMD("shutdown -h now") },
	{MODKEY|ControlMask,            XK_r,         			spawn,		SHCMD("reboot") },
	{MODKEY|ControlMask,            0x6cb,        			spawn,		SHCMD("reboot") },
	{MODKEY|ControlMask,            XK_x,         			spawn,		SHCMD("xkill") },
	{MODKEY|ControlMask,            0x6de,        			spawn,		SHCMD("xkill") },

// Сигнал изменения раскладки в Dwmblocks

  	{ 0,                            XK_ISO_Next_Group,          	spawn,          SHCMD("pkill -RTMIN+1 dwmblocks") },

	/* modifier                     key            function                argument */
	{ MODKEY,                       XK_d,				spawn,                  {.v = dmenucmd } },		/* вызов dmenu */
	{ MODKEY,                       0x6d7,			spawn,                  {.v = dmenucmd } },              /* вызов dmenu */
	{ MODKEY,	   		XK_Return,			spawn,                  {.v = termcmd } },		/* вызов терминала */
	{ MODKEY,            		XK_r,				spawn,			{.v = Rofi } },
	{ MODKEY,                       0x6cb,			spawn,			{.v = Rofi } },
	{ MODKEY,                       XK_x,				spawn,                  {.v = bettcmd } },
	{ MODKEY,                       0x6de,			spawn,                  {.v = bettcmd } },

	{ MODKEY,                       XK_b,          togglebar,              {0} },
	{ MODKEY,                       XK_j,          focusstack,             {.i = +1 } },
	{ MODKEY,                       XK_k,          focusstack,             {.i = -1 } },
	{ MODKEY,                       XK_i,          incnmaster,             {.i = +1 } },
	{ MODKEY,                       XK_d,          incnmaster,             {.i = -1 } },
	{ MODKEY,                       XK_h,          setmfact,               {.f = -0.05} },
	{ MODKEY,                       XK_l,          setmfact,               {.f = +0.05} },
	{ MODKEY|ShiftMask,             XK_j,          movestack,              {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_k,          movestack,              {.i = -1 } },
	{ MODKEY|ShiftMask,	       	XK_Return,     zoom,           		{0} },
	{ MODKEY,                       XK_Return,     zoom,                   {0} },
	{ MODKEY|Mod4Mask,              XK_u,          incrgaps,               {.i = +1 } },
	{ MODKEY|Mod4Mask|ShiftMask,    XK_u,          incrgaps,               {.i = -1 } },
	{ MODKEY|Mod4Mask,              XK_i,          incrigaps,              {.i = +1 } },
	{ MODKEY|Mod4Mask|ShiftMask,    XK_i,          incrigaps,              {.i = -1 } },
	{ MODKEY|Mod4Mask,              XK_o,          incrogaps,              {.i = +1 } },
	{ MODKEY|Mod4Mask|ShiftMask,    XK_o,          incrogaps,              {.i = -1 } },
	{ MODKEY|Mod4Mask,              XK_6,          incrihgaps,             {.i = +1 } },
	{ MODKEY|Mod4Mask|ShiftMask,    XK_6,          incrihgaps,             {.i = -1 } },
	{ MODKEY|Mod4Mask,              XK_7,          incrivgaps,             {.i = +1 } },
	{ MODKEY|Mod4Mask|ShiftMask,    XK_7,          incrivgaps,             {.i = -1 } },
	{ MODKEY|Mod4Mask,              XK_8,          incrohgaps,             {.i = +1 } },
	{ MODKEY|Mod4Mask|ShiftMask,    XK_8,          incrohgaps,             {.i = -1 } },
	{ MODKEY|Mod4Mask,              XK_9,          incrovgaps,             {.i = +1 } },
	{ MODKEY|Mod4Mask|ShiftMask,    XK_9,          incrovgaps,             {.i = -1 } },
	{ MODKEY|Mod4Mask,              XK_0,          togglegaps,             {0} },
	{ MODKEY|Mod4Mask|ShiftMask,    XK_0,          defaultgaps,            {0} },
	{ MODKEY,                       XK_Tab,        view,                   {0} },
	{ MODKEY|Mod1Mask,             XK_c,          killclient,             {0} },
	{ MODKEY|ShiftMask,             XK_q,          quit,                   {0} },
	{ MODKEY|ControlMask|ShiftMask, XK_q,          quit,                   {1} },
	{ MODKEY|ShiftMask,             XK_F5,         xrdb,                   {.v = NULL } },
	{ MODKEY,                       XK_t,          setlayout,              {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,          setlayout,              {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,          setlayout,              {.v = &layouts[2]} },
	{ MODKEY,                       XK_space,      setlayout,              {0} },
	{ MODKEY|ShiftMask,             XK_space,      togglefloating,         {0} },
	{ MODKEY,                       XK_0,          view,                   {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,          tag,                    {.ui = ~0 } },
	{ MODKEY,                       XK_comma,      focusmon,               {.i = -1 } },
	{ MODKEY,                       XK_period,     focusmon,               {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,      tagmon,                 {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period,     tagmon,                 {.i = +1 } },
	TAGKEYS(                        XK_1,                                  0)
	TAGKEYS(                        XK_2,                                  1)
	TAGKEYS(                        XK_3,                                  2)
	TAGKEYS(                        XK_4,                                  3)
	TAGKEYS(                        XK_5,                                  4)
	TAGKEYS(                        XK_6,                                  5)
	TAGKEYS(                        XK_7,                                  6)
	TAGKEYS(                        XK_8,                                  7)
	TAGKEYS(                        XK_9,                                  8)
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask           button          function        argument */
	{ ClkLtSymbol,          0,                   Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,                   Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,                   Button2,        zoom,           {0} },
	{ ClkStatusText,        0,                   Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,              Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,              Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,              Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,                   Button1,        view,           {0} },
	{ ClkTagBar,            0,                   Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,              Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,              Button3,        toggletag,      {0} },
};

