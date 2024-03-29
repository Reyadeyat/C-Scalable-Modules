/*
 * Copyright (C) 2023 Reyadeyat
 *
 * Reyadeyat/C-Scalable-Modules is licensed under the
 * BSD 3-Clause "New" or "Revised" License
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * https://reyadeyat.net/LICENSE/C-SCALABLE-MODULES.LICENSE
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/**
 * 
 * Description
 * 
 *
 * @author Mohammad Nabil Mostafa
 * <a href="mailto:code@reyadeyat.net">code@reyadeyat.net</a>
 * 
 * @since 2023.04.01
 */

#include <stdio.h>
#include "module_canvas_0_0_1.h"

void module_canvas_internal_process_0_0_1(Module_CANVAS_Data *module_canvas_data) {
    printf("Module A internal process version %s name %s buffer_size %u debrecated buffer_size_long %lu\n", module_canvas_data->version, module_canvas_data->name, module_canvas_data->buffer_size, module_canvas_data->buffer_size_long);
}

//external
void module_canvas_external_construct_v_0_0_1(Module_CANVAS_Data *module_canvas_data) {
    printf("Module A external construct version %s name %s buffer_size %u debrecated buffer_size_long %lu\n", module_canvas_data->version, module_canvas_data->name, module_canvas_data->buffer_size, module_canvas_data->buffer_size_long);
}

void module_canvas_external_destruct_v_0_0_1(Module_CANVAS_Data *module_canvas_data) {
    printf("Module A external destruct version %s name %s buffer_size %u debrecated buffer_size_long %lu\n", module_canvas_data->version, module_canvas_data->name, module_canvas_data->buffer_size, module_canvas_data->buffer_size_long);
}

int module_canvas_external_process_v_0_0_1(Module_CANVAS_Data *module_canvas_data) {
    printf("Module A external process version %s name %s buffer_size %u debrecated buffer_size_long %lu\n", module_canvas_data->version, module_canvas_data->name, module_canvas_data->buffer_size, module_canvas_data->buffer_size_long);
    module_canvas_internal_process_0_0_1(module_canvas_data);
    return 0;
}
