//
// Created by mnm on 4/10/23.
//

#ifndef MAKE_SYNTH_LIB_MODULE_A_H
#define MAKE_SYNTH_LIB_MODULE_A_H

#include "module_a_data_structures.h"

typedef struct _Module_A_Process_ {
    void (*construct)(Module_A_Data *make_synth_engine);
    void (*destruct)(Module_A_Data *make_synth_engine);
    int (*process)(Module_A_Data *make_synth_engine);
} Module_A_Process;

Module_A_Process* get_module_a_process(char *version_number);

#endif //MAKE_SYNTH_LIB_MODULE_A_H
