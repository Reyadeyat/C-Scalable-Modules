//
// Created by mnm on 4/10/23.
//

#include <stdio.h>
#include "module_a_0_0_1.h"

void module_a_internal_process_0_0_1(Module_A_Data *module_a_data) {
    printf("Module A internal process version %s name %s buffer_size %d debrecated buffer_size_long %d\n", module_a_data->version, module_a_data->name, module_a_data->buffer_size, module_a_data->buffer_size_long);
}

//external
void module_a_external_construct_v_0_0_1(Module_A_Data *module_a_data) {
    printf("Module A external construct version %s name %s buffer_size %d debrecated buffer_size_long %d\n", module_a_data->version, module_a_data->name, module_a_data->buffer_size, module_a_data->buffer_size_long);
}

void module_a_external_destruct_v_0_0_1(Module_A_Data *module_a_data) {
    printf("Module A external destruct version %s name %s buffer_size %d debrecated buffer_size_long %d\n", module_a_data->version, module_a_data->name, module_a_data->buffer_size, module_a_data->buffer_size_long);
}

int module_a_external_process_v_0_0_1(Module_A_Data *module_a_data) {
    printf("Module A external process version %s name %s buffer_size %d debrecated buffer_size_long %d\n", module_a_data->version, module_a_data->name, module_a_data->buffer_size, module_a_data->buffer_size_long);
    module_a_internal_process_0_0_1(module_a_data);
}
