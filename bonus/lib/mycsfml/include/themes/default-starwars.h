/*
** EPITECH PROJECT, 2023
** graphic_corewar [WSL: fedora]
** File description:
** default
*/

#ifndef CLEAR_COLOR
    #define CLEAR_COLOR sfColor_fromRGB(0, 0, 0)
#endif

/*Buttons colors*/
#ifndef BUTTON_BASE
    #define BUTTON_BASE sfColor_fromRGBA(100, 100, 100, 100)
#endif
#ifndef BUTTON_HOVER
    #define BUTTON_HOVER sfColor_fromRGBA(125, 125, 125, 100)
#endif
#ifndef BUTTON_PRESS
    #define BUTTON_PRESS sfColor_fromRGBA(150, 150, 150, 100)
#endif
#ifndef BUTTON_SELECT
    #define BUTTON_SELECT sfColor_fromRGBA(200, 200, 200, 100)
#endif

/*UI elements colors*/
#ifndef LEFT_BARS
    #define LEFT_BARS sfColor_fromRGB(50, 50, 100)
#endif
#ifndef FRAME_BASE
    #define FRAME_BASE sfColor_fromRGBA(0, 0, 0, 0)
#endif
#ifndef BACKGROUND
    #define BACKGROUND sfColor_fromRGB(50, 50, 50)
#endif
#ifndef TOP_BAR
    #define TOP_BAR sfColor_fromRGB(100, 100, 100)
#endif
#ifndef MENU
    #define MENU sfColor_fromRGBA(100, 100, 100, 100)
#endif
#ifndef ITEM_BG
    #define ITEM_BG sfColor_fromRGB(150, 150, 150)
#endif
#ifndef INPUT_COLOR
    #define INPUT_COLOR sfColor_fromRGB(200, 200, 200)
#endif
#ifndef INPUT_TEXT_COLOR
    #define INPUT_TEXT_COLOR sfColor_fromRGB(0, 0, 0)
#endif
#ifndef DROPDOWNCOLOR
    #define DROPDOWNCOLOR sfColor_fromRGB(200, 200, 200)
#endif

#ifndef HANDLES
    #define HANDLES sfColor_fromRGBA(255, 215, 0, 150) // could match text color
#endif

/*Text*/
#ifndef TEXT_COLOR
    #define TEXT_COLOR sfColor_fromRGBA(255, 215, 50, 200)
#endif
#ifndef TEXT_COLOR2
    #define TEXT_COLOR2 sfColor_fromRGBA(255, 215, 50, 100) // for the memory
#endif
#ifndef FONT_TEXT
    #define FONT_TEXT "Starjedi.ttf"
#endif
#ifndef FONT_MEM
    #define FONT_MEM "VeraMono.ttf" // for the memory
#endif
#ifndef FONT_CHAMP
    #define FONT_CHAMP "Galaxy.ttf" // champions names
#endif

/*Sounds*/
#ifndef MUSIC
    #define MUSIC "music.ogg"
#endif
#ifndef MUSICVOLUME
    #define MUSICVOLUME 50
#endif
#ifndef SOUNDVOLUME
    #define SOUNDVOLUME 50
#endif
#ifndef VOLRANGE
    #define VOLRANGE 100
#endif

/*Start*/
#ifndef LOGO
    #define LOGO "logo.png" // start menu logo
#endif
#ifndef START_MENU_BG
    #define START_MENU_BG sfColor_fromRGBA(0, 0, 0, 0)
#endif

/*Cursor*/
#ifndef CURSOR
    #define CURSOR "cursor.png"
#endif
#ifndef PRESS_SOUND
    #define PRESS_SOUND "clickpress.ogg"
#endif
#ifndef RELEASE_SOUND
    #define RELEASE_SOUND "clickrelease.ogg"
#endif

/*Player Colors*/
#ifndef COLOR1
    #define COLOR1 sfColor_fromRGBA(220, 100, 100, 255)
#endif
#ifndef COLOR2
    #define COLOR2 sfColor_fromRGBA(120, 175, 240, 255)
#endif
#ifndef COLOR3
    #define COLOR3 sfColor_fromRGBA(120, 240, 120, 255)
#endif
#ifndef COLOR4
    #define COLOR4 sfColor_fromRGBA(190, 80, 240, 255)
#endif