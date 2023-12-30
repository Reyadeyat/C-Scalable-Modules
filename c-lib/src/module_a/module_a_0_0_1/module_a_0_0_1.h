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

#ifndef C_LIB_MODULE_A_0_0_1_H
#define C_LIB_MODULE_A_0_0_1_H

#include "../module_a_data_structures.h"

//internal
void module_a_internal_process_0_0_1(Module_A_Data *module_a_data);

//external
extern void module_a_external_construct_v_0_0_1(Module_A_Data *module_a_data);
extern void module_a_external_destruct_v_0_0_1(Module_A_Data *module_a_data);
extern int module_a_external_process_v_0_0_1(Module_A_Data *module_a_data);

#endif //C_LIB_MODULE_A_0_0_1_H
