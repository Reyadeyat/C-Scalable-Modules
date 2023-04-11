//
// Created by mnm on 4/10/23.
//

#include <string.h>
#include "module_a.h"
#include "module_a_0_0_0/module_a_0_0_0.h"
#include "module_a_0_0_1/module_a_0_0_1.h"

static Module_A_Process make_synth_v_0_0_0 = { module_a_external_construct_v_0_0_0, module_a_external_destruct_v_0_0_0, module_a_external_process_v_0_0_0 };
static Module_A_Process make_synth_v_0_0_1 = { module_a_external_construct_v_0_0_1, module_a_external_destruct_v_0_0_1, module_a_external_process_v_0_0_1 };

Module_A_Process* get_module_a_process(char *version_number) {
    if (strcmp(version_number, "0.0.0") == 0) {
        return &make_synth_v_0_0_0;
    }
    if (strcmp(version_number, "0.0.1") == 0) {
        return &make_synth_v_0_0_1;
    }
    return NULL;
}