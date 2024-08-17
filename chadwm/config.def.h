#define XF86MonBrightnessDown 0x1008ff03
#define XF86MonBrightnessUp 0x1008ff02

// ------------------------------------------- Appearance ------------------------------------------- //

static const unsigned int borderpx = 1;       // border pixel of windows
static const unsigned int default_border = 0; // to switch back to default border after dynamic border resizing via keybinds
static const unsigned int snap = 32;          // snap pixel
static const unsigned int gappih = 0;         // horiz inner gap between windows
static const unsigned int gappiv = 0;         // vert inner gap between windows
static const unsigned int gappoh = 0;         // horiz outer gap between windows and screen edge
static const unsigned int gappov = 0;         // vert outer gap between windows and screen edge
static int smartgaps = 1;                     // 1 means no outer gap when there is only one window
static const unsigned int systraypinning = 0; // 0: sloppy systray follows selected monitor, >0: pin systray to monitor X
static const unsigned int systrayspacing = 2; // systray spacing
static const int systraypinningfailfirst = 1; // 1: if pinning fails,display systray on the 1st monitor,False: display systray on last monitor
static const int showsystray = 1;             // 0 means no systray
static const int showbar = 1;                 // 0 means no bar

// -------------------------------------------- Top Bar --------------------------------------------- //

enum showtab_modes
{
    showtab_never,
    showtab_auto,
    showtab_nmodes,
    showtab_always
};

static const int showtab = showtab_never;
static const int toptab = True;
static const int topbar = 1; // 0 means bottom bar
static const int horizpadbar = 5;
static const int vertpadbar = 11;
static const int vertpadtab = 33;
static const int horizpadtabi = 15;
static const int horizpadtabo = 15;
static const int scalepreview = 4;
static int tag_preview = 0; // 1 means enable, 0 is off

// --------------------------------------------- Fonts ---------------------------------------------- //

static const char *fonts[] = {
    "Maple Mono NF:size=10",
};

static const int colorfultag = 1; // 0 means use SchemeSel for selected non vacant tag

// --------------------------------------------- Theme ---------------------------------------------- //

#include "themes/onedark.h"

static const char *colors[][3] = {
    // [...] = { fb, bg, border }
    [SchemeNorm] = {gray3, black, gray2},
    [SchemeSel] = {gray4, blue, blue},
    [TabSel] = {blue, gray2, black},
    [TabNorm] = {gray3, black, black},
    [SchemeTag] = {gray3, black, black},
    [SchemeTag1] = {blue, black, black},
    [SchemeTag2] = {red, black, black},
    [SchemeTag3] = {orange, black, black},
    [SchemeTag4] = {green, black, black},
    [SchemeTag5] = {pink, black, black},
    [SchemeLayout] = {green, black, black},
    [SchemeBtnPrev] = {green, black, black},
    [SchemeBtnNext] = {yellow, black, black},
    [SchemeBtnClose] = {red, black, black},
};

// -------------------------------------------- Tagging --------------------------------------------- //

static const char *eww[] = {"eww", "open", "eww", NULL};
static const Launcher launchers[] = {{eww, ""}};

static char *tags[] = {"1", "2", "3", "4", "5", "6", "7", "8", "9"};

static const int tagschemes[] = {
    SchemeTag1,
    SchemeTag2,
    SchemeTag3,
    SchemeTag4,
    SchemeTag5,
    SchemeTag1,
    SchemeTag2,
    SchemeTag3,
    SchemeTag4,
    SchemeTag5,
};

static const unsigned int ulinepad = 4;     // horizontal padding between the underline and tag
static const unsigned int ulinestroke = 2;  // thickness / height of the underline
static const unsigned int ulinevoffset = 0; // how far above the bottom of the bar the line should appear
static const int ulineall = 0;              // 1 to show underline on all tags, 0 for just the active ones

// --------------------------------------------- Rules ---------------------------------------------- //

static const Rule rules[] = {
    /**
     * xprop(1):
     * WM_CLASS(STRING) = instance, class
     * WM_NAME(STRING) = title
     */

    // { class, instance, title, tags mask, iscentered, isfloating, monitor }
    {"Gimp", NULL, NULL, 0, 0, 1, -1},
    {"Firefox", NULL, NULL, 1 << 8, 0, 0, -1},
    {"eww", NULL, NULL, 0, 0, 1, -1},
};

// -------------------------------------------- Layouts --------------------------------------------- //

static const float mfact = 0.50;     // factor of master area size [0.05..0.95]
static const int nmaster = 1;        // number of clients in master area
static const int resizehints = 0;    // 1 means respect size hints in tiled resizals
static const int lockfullscreen = 1; // 1 will force focus on the fullscreen window

#define FORCE_VSPLIT 1 // nrowgrid layout: force two clients to always split vertically
#include "functions.h"

static const Layout layouts[] = {
    // { symbol, arrange function }
    { "D 0",   doubledeck             }, // Master on left, slaves in monocle-like mode on right
    { "[M]",   monocle                },    // All windows on top of eachother

    { "[]",    tile                   },      // Default: Master on left, slaves on right
    { "[TTT]", bstack                 }, // Master on top, slaves on bottom

    { "[@]",   spiral                 },   // Fibonacci spiral
    { "[\\]",  dwindle                }, // Decreasing in size right and leftward

    { "===",   bstackhoriz            },
    { "HHH",   grid                   },
    { "###",   nrowgrid               },
    { "---",   horizgrid              },
    { ":::",   gaplessgrid            },
    { "|M|",   centeredmaster         },
    { ">M>",   centeredfloatingmaster },

    { "><>",   NULL                   }, // No layout function means floating behavior
    { NULL,    NULL                   },  // Exclude designs from the rules
};

// ---------------------------------------- Key Definitions ----------------------------------------- //

#define MODKEY Mod4Mask
#define TAGKEYS(KEY, TAG)                                          \
    {MODKEY, KEY, view, {.ui = 1 << TAG}},                         \
        {MODKEY | ControlMask, KEY, toggleview, {.ui = 1 << TAG}}, \
        {MODKEY | ShiftMask, KEY, tag, {.ui = 1 << TAG}},          \
        {MODKEY | ControlMask | ShiftMask, KEY, toggletag, {.ui = 1 << TAG}},

// ----------------- Helper for spawning shell commands in the pre dwm-5.0 fashion ------------------ //

#define SHCMD(cmd)                                           \
    {                                                        \
        .v = (const char *[]) { "/bin/sh", "-c", cmd, NULL } \
    }

// ------------------------------------------- Commands --------------------------------------------- //

static const char *term[] = {"alacritty", NULL}; // change this to your term

// ----------------------------------------- Keybindings -------------------------------------------- //

#include <X11/XF86keysym.h>

static Key keys[] = {
    // { modifier, key, function, argument }

    // ------------------------------------------ Windows ------------------------------------------- //

    // Toggle bar
    {MODKEY, XK_b, togglebar, {0}},

    // Toggle full screen mode
    {MODKEY | ControlMask, XK_w, tabmode, {-1}},

    // Switch between windows
    {MODKEY, XK_j, focusstack, {.i = +1}},
    {MODKEY, XK_k, focusstack, {.i = -1}},

    // Adjust window width
    {MODKEY, XK_h, setmfact, {.f = -0.05}},
    {MODKEY, XK_l, setmfact, {.f = +0.05}},

    // Adjust window heigth
    {MODKEY | ShiftMask, XK_h, setcfact, {.f = +0.25}},
    {MODKEY | ShiftMask, XK_l, setcfact, {.f = -0.25}},

    // Move windows in current stack
    {MODKEY | ShiftMask, XK_j, movestack, {.i = +1}},
    {MODKEY | ShiftMask, XK_k, movestack, {.i = -1}},

    // Focus next - prev monitor
    {MODKEY, XK_comma, focusmon, {.i = -1}},
    {MODKEY, XK_period, focusmon, {.i = +1}},

    // Send window to next - prev monitor
    {MODKEY | ShiftMask, XK_comma, tagmon, {.i = -1}},
    {MODKEY | ShiftMask, XK_period, tagmon, {.i = +1}},

    // Adjust Overall gaps
    {MODKEY | ControlMask, XK_i, incrgaps, {.i = +1}},
    {MODKEY | ControlMask, XK_d, incrgaps, {.i = -1}},

    // Adjust Inner gaps
    {MODKEY | ShiftMask, XK_i, incrigaps, {.i = +1}},
    {MODKEY | ControlMask | ShiftMask, XK_i, incrigaps, {.i = -1}},

    // Adjust Outer gaps
    {MODKEY | ControlMask, XK_o, incrogaps, {.i = +1}},
    {MODKEY | ControlMask | ShiftMask, XK_o, incrogaps, {.i = -1}},
    {MODKEY | ControlMask, XK_6, incrihgaps, {.i = +1}},
    {MODKEY | ControlMask | ShiftMask, XK_6, incrihgaps, {.i = -1}},
    {MODKEY | ControlMask, XK_7, incrivgaps, {.i = +1}},
    {MODKEY | ControlMask | ShiftMask, XK_7, incrivgaps, {.i = -1}},
    {MODKEY | ControlMask, XK_8, incrohgaps, {.i = +1}},
    {MODKEY | ControlMask | ShiftMask, XK_8, incrohgaps, {.i = -1}},
    {MODKEY | ControlMask, XK_9, incrovgaps, {.i = +1}},
    {MODKEY | ControlMask | ShiftMask, XK_9, incrovgaps, {.i = -1}},

    // Default gaps
    {MODKEY | ControlMask | ShiftMask, XK_d, defaultgaps, {0}},

    // Adjust window border
    {MODKEY | ShiftMask, XK_p, setborderpx, {.i = +1}},
    {MODKEY | ShiftMask, XK_minus, setborderpx, {.i = -1}},

    // Change the format of layouts
    // {MODKEY, XK_i, incnmaster, {.i = +1}},
    // {MODKEY, XK_d, incnmaster, {.i = -1}},

    {MODKEY, XK_u, setlayout, {.v = &layouts[0]}},             // doubledeck
    {MODKEY | ShiftMask, XK_u, setlayout, {.v = &layouts[1]}}, // monocle
    {MODKEY, XK_y, setlayout, {.v = &layouts[2]}},             // tile
    {MODKEY | ShiftMask, XK_y, setlayout, {.v = &layouts[3]}}, // bstack
    {MODKEY, XK_t, setlayout, {.v = &layouts[4]}},             // spiral
    {MODKEY | ShiftMask, XK_t, setlayout, {.v = &layouts[5]}}, // dwindle

    // Reset window border
    {MODKEY | ShiftMask, XK_w, setborderpx, {.i = default_border}},

    // Cycle layouts
    {MODKEY, XK_Tab, cyclelayout, {.i = +1}},
    {MODKEY | ShiftMask, XK_Tab, cyclelayout, {.i = -1}},

    // Kill window
    {MODKEY, XK_q, killclient, {0}},

    // Full screen
    {MODKEY, XK_f, togglefullscr, {0}},

    // Focus screen
    {MODKEY, XK_space, zoom, {0}},

    // Toggle floating
    {MODKEY | ShiftMask, XK_f, togglefloating, {0}},

    // Restart dwm
    {MODKEY | ControlMask, XK_r, quit, {1}},

    // Quit dwm
    {MODKEY | ControlMask, XK_q, quit, {0}},

    // ----------------------------------------- Workspaces ----------------------------------------- //

    TAGKEYS(XK_1, 0)
        TAGKEYS(XK_2, 1)
            TAGKEYS(XK_3, 2)
                TAGKEYS(XK_4, 3)
                    TAGKEYS(XK_5, 4)
                        TAGKEYS(XK_6, 5)
                            TAGKEYS(XK_7, 6)
                                TAGKEYS(XK_8, 7)
                                    TAGKEYS(XK_9, 8)

    // ---------------------------------------- Applications ---------------------------------------- //

    // Apps
    {MODKEY, XK_m, spawn, SHCMD("rofi -show drun")},

    // Windows
    {MODKEY | ShiftMask, XK_m, spawn, SHCMD("rofi -show window")},

    // Emojis
    {MODKEY | ShiftMask, XK_e, spawn, SHCMD("rofi -show emoji")},

    // Terminal
    {MODKEY | ShiftMask, XK_Return, spawn, SHCMD("wezterm")},
    {MODKEY, XK_Return, spawn, SHCMD("pkill tmux; wezterm -e n-start-tmux")},

    // Browser
    {MODKEY | ShiftMask, XK_w, spawn, SHCMD("google-chrome-stable")},
    {MODKEY, XK_w, spawn, SHCMD("brave")},

    // File Explorer
    {MODKEY, XK_e, spawn, SHCMD("pcmanfm")},

    // Editor
    {MODKEY, XK_c, spawn, SHCMD("code")},

    // Anki
    {MODKEY, XK_a, spawn, SHCMD("anki")},

    // Database Manager
    {MODKEY, XK_d, spawn, SHCMD("beekeeper-studio")},

    // Rest Client
    {MODKEY, XK_p, spawn, SHCMD("postman")},

    // Redshift
    {MODKEY, XK_r, spawn, SHCMD("redshift -O 6000")},
    {MODKEY | ShiftMask, XK_r, spawn, SHCMD("redshift -x")},

    // Screenshot
    {MODKEY, XK_s, spawn, SHCMD("flameshot gui")},

    // Screenshot with delay
    {MODKEY | ShiftMask, XK_s, spawn, SHCMD("scrot -u -d 3")},

    // ------------------------------------------ Hardware ------------------------------------------ //

    // Volume
    {0, XF86XK_AudioLowerVolume, spawn, SHCMD("pactl set-sink-volume @DEFAULT_SINK@ -2%")},
    {0, XF86XK_AudioRaiseVolume, spawn, SHCMD("pactl set-sink-volume @DEFAULT_SINK@ +2%")},
    {0, XF86XK_AudioMute, spawn, SHCMD("pactl set-sink-mute @DEFAULT_SINK@ toggle")},

    // Brightness
    {0, XF86XK_MonBrightnessUp, spawn, SHCMD("brightnessctl set +2%")},
    {0, XF86XK_MonBrightnessDown, spawn, SHCMD("brightnessctl set 2%-")},
};

// -------------------------------------- Button Definitions ---------------------------------------- //

// click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin
static Button buttons[] = {
    // { click, event mask, button, function, argument }
    {ClkLtSymbol, 0, Button1, setlayout, {0}},
    {ClkLtSymbol, 0, Button3, setlayout, {.v = &layouts[2]}},
    {ClkWinTitle, 0, Button2, zoom, {0}},
    {ClkStatusText, 0, Button2, spawn, {.v = term}},

    // Keep movemouse?
    // { ClkClientWin, MODKEY, Button1, movemouse, {0} },

    /**
     * Placemouse options, choose which feels more natural:
     *      * 0 - tiled position is relative to mouse cursor
     *      * 1 - tiled postiion is relative to window center
     *      * 2 - mouse pointer warps to window center

     * The moveorplace uses movemouse or placemouse depending on the floating state
     * of the selected client. Set up individual keybindings for the two if you want
     * to control these separately (i.e. to retain the feature to move a tiled window
     * into a floating position).
     */

    {ClkClientWin, MODKEY, Button1, moveorplace, {.i = 0}},
    {ClkClientWin, MODKEY, Button2, togglefloating, {0}},
    {ClkClientWin, MODKEY, Button3, resizemouse, {0}},
    {ClkClientWin, ControlMask, Button1, dragmfact, {0}},
    {ClkClientWin, ControlMask, Button3, dragcfact, {0}},
    {ClkTagBar, 0, Button1, view, {0}},
    {ClkTagBar, 0, Button3, toggleview, {0}},
    {ClkTagBar, MODKEY, Button1, tag, {0}},
    {ClkTagBar, MODKEY, Button3, toggletag, {0}},
    {ClkTabBar, 0, Button1, focuswin, {0}},
    {ClkTabBar, 0, Button1, focuswin, {0}},
    {ClkTabPrev, 0, Button1, movestack, {.i = -1}},
    {ClkTabNext, 0, Button1, movestack, {.i = +1}},
    {ClkTabClose, 0, Button1, killclient, {0}},
};
