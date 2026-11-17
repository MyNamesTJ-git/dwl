/* Merge these sections into your copy of config.def.h */

#define MODKEY WLR_MODIFIER_LOGO
#define ALT    WLR_MODIFIER_ALT
#define CTRL   WLR_MODIFIER_CTRL
#define SHIFT  WLR_MODIFIER_SHIFT

/* Appearance (Nord) */
static const unsigned int borderpx = 3;
static const float rootcolor[]       = COLOR(0x2E3440ff);
static const float bordercolor[]     = COLOR(0x4C566Aff);
static const float focuscolor[]      = COLOR(0x88C0D0ff);
static const float urgentcolor[]     = COLOR(0xBF616Aff);
static const float fullscreen_bg[]   = {0.18f, 0.20f, 0.25f, 1.0f};

/* Input */
static const struct xkb_rule_names xkb_rules = {
	.layout = "us",
};
static const int repeat_rate = 25;
static const int repeat_delay = 600;
static const int tap_to_click = 1;
static const int tap_and_drag = 1;
static const int drag_lock = 1;
static const int natural_scrolling = 0;
static const int disable_while_typing = 0;
static const int sloppyfocus = 1;

/* Commands */
static const char *termcmd[]     = { "kitty", NULL };
static const char *browsercmd[]  = { "librewolf", NULL };
static const char *privatecmd[]  = { "librewolf", "--private-window", NULL };
static const char *menucmd[]     = { "rofi", "-show", "drun", NULL };
static const char *filescmd[]    = { "thunar", NULL };
static const char *lockcmd[]     = { "swaylock", "-f", "-c", "2E3440", NULL };

#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

#define TAGKEYS(KEY,SKEY,TAG) \
	{ MODKEY,        KEY,  view, {.ui = 1 << TAG} }, \
	{ MODKEY|CTRL,   KEY,  toggleview, {.ui = 1 << TAG} }, \
	{ MODKEY|SHIFT,  SKEY, tag, {.ui = 1 << TAG} }

#define CHVT(n) { WLR_MODIFIER_CTRL|WLR_MODIFIER_ALT, XKB_KEY_XF86Switch_VT_##n, chvt, {.ui = (n)} }

static const Key keys[] = {
	/* launch */
	{ MODKEY,        XKB_KEY_Return, spawn, {.v = termcmd} },
	{ MODKEY,        XKB_KEY_b,      spawn, {.v = browsercmd} },
	{ MODKEY|SHIFT,  XKB_KEY_B,      spawn, {.v = privatecmd} },
	{ MODKEY,        XKB_KEY_d,      spawn, {.v = menucmd} },
	{ MODKEY|SHIFT,  XKB_KEY_D,      spawn, {.v = menucmd} },
	{ MODKEY|SHIFT,  XKB_KEY_L,      spawn, {.v = lockcmd} },
	{ MODKEY,        XKB_KEY_e,      spawn, {.v = filescmd} },

	/* window */
	{ MODKEY,        XKB_KEY_q,         killclient, {0} },
	{ MODKEY|SHIFT,  XKB_KEY_ISO_Left_Tab, focusstack, {.i = +1} },
	{ MODKEY,        XKB_KEY_space,     togglefloating, {0} },
	{ MODKEY,        XKB_KEY_f,         togglefullscreen, {0} },
	{ MODKEY,        XKB_KEY_z,         setlayout, {.v = &layouts[0]} },
	{ MODKEY|SHIFT,  XKB_KEY_H,         setmfact, {.f = -0.05f} },
	{ MODKEY|SHIFT,  XKB_KEY_Left,      setmfact, {.f = -0.05f} },
	{ MODKEY|SHIFT,  XKB_KEY_Right,     setmfact, {.f = +0.05f} },

	/* monitors */
	{ MODKEY,             XKB_KEY_bracketleft,  focusmon, {.i = WLR_DIRECTION_LEFT} },
	{ MODKEY,             XKB_KEY_bracketright, focusmon, {.i = WLR_DIRECTION_RIGHT} },
	{ MODKEY|SHIFT,       XKB_KEY_braceleft,    tagmon,   {.i = WLR_DIRECTION_LEFT} },
	{ MODKEY|SHIFT,       XKB_KEY_braceright,   tagmon,   {.i = WLR_DIRECTION_RIGHT} },
	{ ALT|SHIFT,          XKB_KEY_H, focusmon, {.i = WLR_DIRECTION_LEFT} },
	{ ALT|SHIFT,          XKB_KEY_L, focusmon, {.i = WLR_DIRECTION_RIGHT} },
	{ ALT|SHIFT,          XKB_KEY_K, focusmon, {.i = WLR_DIRECTION_UP} },
	{ ALT|SHIFT,          XKB_KEY_J, focusmon, {.i = WLR_DIRECTION_DOWN} },
	{ MODKEY|ALT|SHIFT,   XKB_KEY_H, tagmon, {.i = WLR_DIRECTION_LEFT} },
	{ MODKEY|ALT|SHIFT,   XKB_KEY_L, tagmon, {.i = WLR_DIRECTION_RIGHT} },
	{ MODKEY|ALT|SHIFT,   XKB_KEY_K, tagmon, {.i = WLR_DIRECTION_UP} },
	{ MODKEY|ALT|SHIFT,   XKB_KEY_J, tagmon, {.i = WLR_DIRECTION_DOWN} },

	/* tags */
	TAGKEYS(XKB_KEY_1, XKB_KEY_exclam,      0),
	TAGKEYS(XKB_KEY_2, XKB_KEY_at,          1),
	TAGKEYS(XKB_KEY_3, XKB_KEY_numbersign,  2),
	TAGKEYS(XKB_KEY_4, XKB_KEY_dollar,      3),
	TAGKEYS(XKB_KEY_5, XKB_KEY_percent,     4),
	TAGKEYS(XKB_KEY_6, XKB_KEY_asciicircum, 5),
	TAGKEYS(XKB_KEY_7, XKB_KEY_ampersand,   6),
	TAGKEYS(XKB_KEY_8, XKB_KEY_asterisk,    7),
	TAGKEYS(XKB_KEY_9, XKB_KEY_parenleft,   8),

	/* screenshots */
	{ MODKEY,             XKB_KEY_s, spawn, SHCMD("grim - | wl-copy -t image/png") },
	{ MODKEY|SHIFT,       XKB_KEY_S, spawn, SHCMD("grim -g \"$(slurp)\" - | wl-copy -t image/png") },
	{ MODKEY|CTRL,        XKB_KEY_s, spawn, SHCMD("grim ~/Screenshots/$(date +%Y-%m-%d_%H-%M-%S).png") },
	{ MODKEY|CTRL|SHIFT,  XKB_KEY_S, spawn, SHCMD("grim -g \"$(slurp)\" ~/Screenshots/$(date +%Y-%m-%d_%H-%M-%S).png") },

	/* media */
	{ 0, XKB_KEY_XF86AudioRaiseVolume,  spawn, SHCMD("wpctl set-volume @DEFAULT_AUDIO_SINK@ 5%+ --limit 1.0") },
	{ 0, XKB_KEY_XF86AudioLowerVolume,  spawn, SHCMD("wpctl set-volume @DEFAULT_AUDIO_SINK@ 5%-") },
	{ 0, XKB_KEY_XF86AudioMute,         spawn, SHCMD("wpctl set-mute @DEFAULT_AUDIO_SINK@ toggle") },
	{ 0, XKB_KEY_XF86AudioMicMute,      spawn, SHCMD("wpctl set-mute @DEFAULT_AUDIO_SOURCE@ toggle") },
	{ 0, XKB_KEY_XF86MonBrightnessUp,   spawn, SHCMD("brightnessctl set 5%+") },
	{ 0, XKB_KEY_XF86MonBrightnessDown, spawn, SHCMD("brightnessctl set 5%-") },
	{ 0, XKB_KEY_XF86AudioPlay,         spawn, SHCMD("playerctl play-pause") },
	{ 0, XKB_KEY_XF86AudioNext,         spawn, SHCMD("playerctl next") },
	{ 0, XKB_KEY_XF86AudioPrev,         spawn, SHCMD("playerctl previous") },
	{ MODKEY, XKB_KEY_slash,            spawn, SHCMD("playerctl play-pause") },
	{ MODKEY, XKB_KEY_period,           spawn, SHCMD("playerctl next") },
	{ MODKEY, XKB_KEY_comma,            spawn, SHCMD("playerctl previous") },

	/* session safety (not in your mango config) */
	{ MODKEY|SHIFT, XKB_KEY_Q, quit, {0} },
	CHVT(1), CHVT(2), CHVT(3), CHVT(4), CHVT(5), CHVT(6),
};
