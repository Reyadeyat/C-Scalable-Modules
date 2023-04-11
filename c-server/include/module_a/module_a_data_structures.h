//
// Created by mnm on 4/10/23.
//

#ifndef MAKE_SYNTH_LIB_MODULE_A_DATA_STRUCTURES_H
#define MAKE_SYNTH_LIB_MODULE_A_DATA_STRUCTURES_H

typedef struct _Module_A_Data_ {
    /**@since 0.0.0*/
    char* version;
    /**@since 0.0.0*/
    char* name;
    /**@debrecated 0.0.1*/
    int buffer_size;
    /**@since 0.0.1*/
    long buffer_size_long;
} Module_A_Data;

#endif //MAKE_SYNTH_LIB_MODULE_A_DATA_STRUCTURES_H
