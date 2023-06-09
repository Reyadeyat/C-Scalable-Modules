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
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "module-a/module-a.h"

int main(int argc, char **argv) {
    int len = strlen(argv[0]) + 1 + 1024;
    char path[len];
    memcpy(path, argv[0], strlen(argv[0])+1);
    printf ("Program dir: %s\n", path);
    char *start = strstr(path, "/bin");
    char *lib_dir = "/lib/c-lib-module-a.so";
    strncpy(start, lib_dir, strlen(lib_dir)+1);
    printf ("Lib dir: %s\n", path);
    void* handle = dlopen(path, RTLD_LAZY);
    char* dl_error = (char*) dlerror();
    if (handle == NULL) {
        printf("Error Loading lib file '%s' => %s\n", path, dl_error);
    } else {

		int ret;
        start[5]='\0';
        printf ("Lib dir prefix is : %s\n", path);

        Module_A_Process* (*get_module_a_process)(char *, char *);
        get_module_a_process = dlsym(handle, "get_module_a_process");
        if (get_module_a_process == NULL) {
            printf ("Error loading function get_module_a_process\n");
        }

        char path_copy[len];
        memcpy(path_copy, path, strlen(path)+1);
        printf ("Calling get_module_a_process 0.0.0 path => %s\n", path_copy);
        Module_A_Process* module_a_process_0_0_0 = get_module_a_process((char*) path_copy, "0.0.0");
        Module_A_Data module_a_data_0_0_0 = {"0.0.0", "Module_A_Data_0_0_0", 32};
        ret = module_a_process_0_0_0->process(&module_a_data_0_0_0);
        if (ret < 0) {
            perror("Error: module_a_process_0_0_0->process\n");
            ret = -1;
            goto error_0_0_0;
        }

        memcpy(path_copy, path, strlen(path)+1);
        printf ("Calling get_module_a_process 0.0.1 path => %s\n", path_copy);
        Module_A_Process* module_a_process_0_0_1 = get_module_a_process((char*) path_copy, "0.0.1");
        Module_A_Data module_a_data_0_0_1 = {"0.0.1", "Module_A_Data_0_0_1", 0, 64};
        ret = module_a_process_0_0_1->process(&module_a_data_0_0_1);

        if (ret < 0) {
            perror("Error: module_a_process_0_0_1->process\n");
            ret = -1;
            goto error_0_0_1;
        }
        
        goto error0;

        error_0_0_1:
        printf("Error in module_a_process_0_0_1 ret=%d\n",ret);
        module_a_process_0_0_1->destruct(&module_a_data_0_0_1);
        error_0_0_0:
        printf("Error in module_a_process_0_0_0 ret=%d\n",ret);
        module_a_process_0_0_0->destruct(&module_a_data_0_0_0);
        error0:
        printf("Completed Successfully\n");
        return ret;
    }
}
