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


#ifndef C_LIB_MODULE_CANVAS_H
#define C_LIB_MODULE_CANVAS_H

#include "module_canvas_data_structures.h"

typedef struct _Module_CANVAS_Process_ {
    void (*construct)(Module_CANVAS_Data *module_canvas_data);
    void (*destruct)(Module_CANVAS_Data *module_canvas_data);
    int (*process)(Module_CANVAS_Data *module_canvas_data);
} Module_CANVAS_Process;

extern Module_CANVAS_Process* get_module_canvas_process(char* lib_path, char *version_number);

#endif //C_LIB_MODULE_CANVAS_H
