#include <dlfcn.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

#include "module_a/module_a.h"

int main(int argc, char **argv) {
    char path [1024];
    strncpy(path, argv[0], strlen(argv[0]));
    char *start = strstr(path, "/bin");
    char *lib_dir = "/lib/libc-lib.so";
    strncpy(start, lib_dir, strlen(lib_dir)+1);
    printf ("\nLib dir: %s\n", path);
    //strlen(argv[0])-strlen(start)
    //getcwd (path, 1024);
    //printf ("\nCurrent working dir: %s\n", path);
    //strcat(path, "/../lib/libc-lib.so");
    void* handle = dlopen(path, RTLD_LAZY);
    char* dl_error = dlerror();
    if (handle == NULL) {
        // report error ...
        printf("Allaho Akbar - Error Loading lib file => %s\n", dl_error);
    } else {

		int ret;

        Module_A_Process* (*get_module_a_process)(char *);
        get_module_a_process = dlsym(handle, "get_module_a_process");

        Module_A_Process* module_a_process_0_0_0 = get_module_a_process("0.0.0");
        Module_A_Data module_a_data_0_0_0 = {"0.0.0", "Module_A_Data_0_0_0", 32};
        ret = module_a_process_0_0_0->process(&module_a_data_0_0_0);
        if (ret < 0) {
            perror("Error: module_a_process_0_0_0->process\n");
            ret = -1;
            goto error_0_0_0;
        }

        Module_A_Process* module_a_process_0_0_1 = get_module_a_process("0.0.1");
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
