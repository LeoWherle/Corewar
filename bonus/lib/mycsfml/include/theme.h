/*
** EPITECH PROJECT, 2022
** Libmycsfml
** File description:
** Header for theme
*/

#ifndef THEME_H
    #define THEME_H

    #define CLEAR_COLOR sfColor_fromRGB(0, 0, 0)
    
    /*Buttons colors*/
    #define BUTTON_BASE sfColor_fromRGBA(100, 100, 100, 100)
    #define BUTTON_HOVER sfColor_fromRGBA(125, 125, 125, 100)
    #define BUTTON_PRESS sfColor_fromRGBA(150, 150, 150, 100)
    #define BUTTON_SELECT sfColor_fromRGBA(200, 200, 200, 100)

    /*UI elements colors*/
    #define LEFT_BARS sfColor_fromRGB(50, 50, 100)
    #define FRAME_BASE sfColor_fromRGBA(0, 0, 0, 0)
    #define BACKGROUND sfColor_fromRGB(50, 50, 50)
    #define TOP_BAR sfColor_fromRGB(100, 100, 100)
    #define MENU sfColor_fromRGBA(100, 100, 100, 100)
    #define ITEM_BG sfColor_fromRGB(150, 150, 150)
    #define INPUT_COLOR sfColor_fromRGB(200, 200, 200)
    #define INPUT_TEXT_COLOR sfColor_fromRGB(0, 0, 0)
    #define DROPDOWNCOLOR sfColor_fromRGB(200, 200, 200)

    #define HANDLES sfColor_fromRGBA(255, 215, 0, 150) // could match text color

    /*Text*/
    #define TEXT_COLOR sfColor_fromRGBA(255, 215, 50, 200)
    #define TEXT_COLOR2 sfColor_fromRGBA(255, 215, 50, 100) // for the memory
    #define FONT_TEXT "Starjedi.ttf"
    #define FONT_MEM "VeraMono.ttf" // for the memory
    #define FONT_CHAMP "Galaxy.ttf" // champions names

    /*Sounds*/
    #define MUSIC "music.ogg"
    #define MUSICVOLUME 50
    #define SOUNDVOLUME 50
    #define VOLRANGE 100

    /*Start*/
    #define LOGO "logo.png" // start menu logo
    #define START_MENU_BG sfColor_fromRGBA(0, 0, 0, 0)

    /*Cursor*/
    #define CURSOR "cursor.png"
    #define PRESS_SOUND "clickpress.ogg"
    #define RELEASE_SOUND "clickrelease.ogg"

#endif /* THEME_H */
