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

#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "module_a.h"

Module_A_Process* get_module_a_process(char* lib_path, char *version_number) {
    printf("get_module_a_process lib_path => %s\n", lib_path);
    if (strcmp(version_number, "0.0.0") == 0) {
        strcat(lib_path, "c-lib-module-a.0.0.0.so");
        printf("lib_path => %s\n", lib_path);
        void* handle = dlopen(lib_path, RTLD_LAZY);
        char* dl_error = dlerror();
        if (handle == NULL) {
            printf("Error Loading lib file '%s' => %s\n", lib_path, dl_error);
            return NULL;
        }
        void (*module_a_external_construct)(Module_A_Data*);
        void (*module_a_external_destruct)(Module_A_Data*);
        int (*module_a_external_process)(Module_A_Data*);
        module_a_external_construct = dlsym(handle, "module_a_external_construct_v_0_0_0");
        module_a_external_destruct = dlsym(handle, "module_a_external_destruct_v_0_0_0");
        module_a_external_process = dlsym(handle, "module_a_external_process_v_0_0_0");
        Module_A_Process *module_a_process = malloc(sizeof(Module_A_Process));
        module_a_process->construct = module_a_external_construct;
        module_a_process->destruct = module_a_external_destruct;
        module_a_process->process = module_a_external_process;
        return module_a_process;
    }
    if (strcmp(version_number, "0.0.1") == 0) {
        strcat(lib_path, "c-lib-module-a.0.0.1.so");
        printf("lib_path => %s\n", lib_path);
        void* handle = dlopen(lib_path, RTLD_LAZY);
        char* dl_error = (char*) dlerror();
        if (handle == NULL) {
            printf("Error Loading lib file '%s' => %s\n", lib_path, dl_error);
            return NULL;
        }
        void (*module_a_external_construct)(Module_A_Data*);
        void (*module_a_external_destruct)(Module_A_Data*);
        int (*module_a_external_process)(Module_A_Data*);
        module_a_external_construct = dlsym(handle, "module_a_external_construct_v_0_0_1");
        module_a_external_destruct = dlsym(handle, "module_a_external_destruct_v_0_0_1");
        module_a_external_process = dlsym(handle, "module_a_external_process_v_0_0_1");
        Module_A_Process *module_a_process = malloc(sizeof(Module_A_Process));
        module_a_process->construct = module_a_external_construct;
        module_a_process->destruct = module_a_external_destruct;
        module_a_process->process = module_a_external_process;
        return module_a_process;
    }
    return NULL;
}