/*
** EPITECH PROJECT, 2022
** Libmycsfml
** File description:
** Header for input panels
*/

#ifndef INPUT_H
    #define INPUT_H
    #include <SFML/Graphics.h>

typedef enum entry_type_s {
    EntryTypeLetter,
    EntryTypeNumber
} entry_type_t;

typedef struct panel_input_s {
    entry_type_t type;
    char *text;
    int max_size;
    int left;
    unsigned int *trgt_int;
    char **trgt_str;
} panel_input_t;

panel_t *make_name_input(sfFont *font, char **trgt);
panel_t *panel_input_create(
    rectransform_t *, sfFont *, entry_type_t, const char *);
void panel_input_destroy(panel_t *);

void on_text_entered(sfTextEvent, panel_t *);
#endif /* PANEL_INPUT_H */
