/*
** EPITECH PROJECT, 2023
** Libmycsfml
** File description:
** VM container
*/

#include <stdlib.h>
#include <stdio.h>
#include "vm.h"
#include "demo.h"
#include "ui_panels/slider.h"

vm_container_t *vm_container_create(program_t *p, vm_t *vm)
{
    vm_container_t *vmc = NULL;
    panel_t *control = p->scenes[1]->canvas->panels[0]->childs[0]->childs[0]->childs[0];

    vmc = malloc(sizeof(vm_container_t));
    if (!vmc)
        return NULL;
    vmc->vm = vm;
    vmc->vmflex = p->scenes[1]->canvas->panels[0]->childs[0]->childs[2];
    vmc->winpanel = p->scenes[1]->canvas->panels[0]->childs[0]->childs[1];
    vmc->seconds = 0;
    vmc->timescale = 0;
    ((panel_slider_t *)(control->childs[3]->childs[1]->childs[1]->data))->trgt = vmc;
    vmc->timescaleText = control->childs[3]->childs[0]->childs[1]->text;
    vmc->champ1text = control->childs[0]->childs[0]->childs[1]->text;
    sfText_setColor(control->childs[0]->childs[0]->childs[0]->text, COLOR1);
    sfText_setString(control->childs[0]->childs[0]->childs[0]->text,
        ((champion_t *) vm->champions->head->data)->header.prog_name);
    vmc->champ2text = control->childs[0]->childs[1]->childs[1]->text;
    sfText_setColor(control->childs[0]->childs[1]->childs[0]->text, COLOR2);
    sfText_setString(control->childs[0]->childs[1]->childs[0]->text,
        ((champion_t *) vm->champions->head->next->data)->header.prog_name);
    if (vm->champions->size > 2) {
        vmc->champ3text = control->childs[1]->childs[0]->childs[1]->text;
        sfText_setColor(control->childs[1]->childs[0]->childs[0]->text, COLOR3);
        sfText_setString(control->childs[1]->childs[0]->childs[0]->text,
        ((champion_t *) vm->champions->head->next->next->data)->header.prog_name);
    }
    if (vm->champions->size > 3) {
        vmc->champ4text = control->childs[1]->childs[1]->childs[1]->text;
        sfText_setColor(control->childs[1]->childs[1]->childs[0]->text, COLOR4);
        sfText_setString(control->childs[1]->childs[1]->childs[0]->text,
        ((champion_t *) vm->champions->head->next->next->next->data)->header.prog_name);
    }
    control = control->childs[2];
    vmc->cycleText = control->childs[0]->childs[1]->text;
    vmc->totalcycleText = control->childs[1]->childs[1]->text;
    vmc->nblivetext = control->childs[2]->childs[1]->text;
    return vmc;
}

void vm_container_destroy(vm_container_t *vmc)
{
    free(vmc->vm->champions->interface);
    vm_destroy(vmc->vm);
    free(vmc);
}

void update_text(sfText *text, const char *str)
{
    sfFloatRect trect;

    sfText_setString(text, str);
    trect = sfText_getLocalBounds(text);
    sfText_setOrigin(text, (sfVector2f){
        trect.left + trect.width / 2.0f, trect.top + trect.height / 2.0f});
}

void vm_stats_update(vm_container_t *vmc)
{
    char str[20] = {0};
    sprintf(str, "%i", vmc->vm->total_cycle);
    update_text(vmc->totalcycleText, str);
    sprintf(str, "%i / %i", vmc->vm->cycle_amount, vmc->vm->cycle_to_die);
    update_text(vmc->cycleText, str);
    sprintf(str, "%i / %i", vmc->vm->local_live, NBR_LIVE);
    update_text(vmc->nblivetext, str);
}

void vm_champ_update(vm_container_t *vmc)
{
    int count[4] = {0, 0, 0, 0};
    node_t *proc = vmc->vm->process->head;
    char str[10] = {0};

    while (proc) {
        count[((process_t *)proc->data)->champion->id - 1]++;
        proc = proc->next;
    }
    sprintf(str, "%i", count[0]);
    update_text(vmc->champ1text, str);
    sprintf(str, "%i", count[1]);
    update_text(vmc->champ2text, str);
    if (vmc->vm->champions->size <= 2)
        return;
    sprintf(str, "%i", count[2]);
    update_text(vmc->champ3text, str);
    if (vmc->vm->champions->size <= 3)
        return;
    sprintf(str, "%i", count[3]);
    update_text(vmc->champ4text, str);
}

void vmflex_update(vm_container_t *vmc)
{
    int i = 0;
    char hexa[] = "OO";
    const char hexadict[] = "O123456789ABCDEF";
    unsigned char tmp = 0;

    for (; i < MEM_SIZE && vmc->vmflex->childs[i]; i++) {
        tmp = cbuffer_getb(vmc->vm->arena, i);
        hexa[0] = hexadict[tmp / 16];
        hexa[1] = hexadict[tmp % 16];
        sfText_setString(vmc->vmflex->childs[i]->text, hexa);
        switch (cbuffer_getb(vmc->vm->arena_ownership, i)) {
            case 1:
                sfText_setColor(vmc->vmflex->childs[i]->text, COLOR1);
                break;
            case 2:
                sfText_setColor(vmc->vmflex->childs[i]->text, COLOR2);
                break;
            case 3:
                sfText_setColor(vmc->vmflex->childs[i]->text, COLOR3);
                break;
            case 4:
                sfText_setColor(vmc->vmflex->childs[i]->text, COLOR4);
                break;
        }
    }
}

void vmproc_update(vm_container_t *vmc)
{
    node_t *proc = vmc->vm->process->head;

    while (proc) {
        for (size_t i = 0; i < MEM_SIZE; i++) {
            if (((process_t *)proc->data)->index == i) {
                sfText_setColor(vmc->vmflex->childs[i]->text, sfWhite);
                break;
            }
        }
        proc = proc->next;
    }
}

int vm_container_update(vm_container_t *vmc, float seconds)
{
    int ret = 0;
    vmc->seconds += seconds * vmc->timescale;
    while (vmc->seconds >= 1.0 / CYCLE_PER_SEC) {
        vmc->seconds -= 1.0 / CYCLE_PER_SEC;
        if (vmc->vm->cycle_to_die <= 0) {
            ret = -1;
            break;
        }
        instruction_get(vmc->vm);
        instruction_exec(vmc->vm);
        if (core_check(vmc->vm)) {
            ret = -1;
            vmc->winpanel->state = PANEL_STATE_ACTIVE;
            update_text(vmc->winpanel->childs[1]->text, vmc->vm->last_live->header.prog_name);
            break;
        }
    }
    vm_stats_update(vmc);
    vm_champ_update(vmc);
    vmflex_update(vmc);
    vmproc_update(vmc);
    return ret;
}