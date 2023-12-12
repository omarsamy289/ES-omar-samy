/*
 * stat.h
 *
 *  Created on: Dec 12, 2023
 *      Author: omar
 */

#ifndef STATE_H_
#define STATE_H_
#include "stdio.h"
#include "stdlib.h"

// state definitio macros
#define state_definition(state_func) void SD_##state_func()
#define state_name(state_func) SD_##state_func

// connections between blocks
void US_set_distance (int di) ;
void DC_get_speed (int sp ) ;



#endif /* STATE_H_ */
