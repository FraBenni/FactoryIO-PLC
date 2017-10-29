#ifndef __POUS_H
#define __POUS_H

#include "accessor.h"
#include "iec_std_lib.h"

// PROGRAM SCENE1
// Data part
typedef struct {
  // PROGRAM Interface - IN, OUT, IN_OUT variables

  // PROGRAM private variables - TEMP, private and located variables
  __DECLARE_LOCATED(BOOL,SENSOR)
  __DECLARE_LOCATED(BOOL,CONV_BELT)

} SCENE1;

void SCENE1_init__(SCENE1 *data__, BOOL retain);
// Code part
void SCENE1_body__(SCENE1 *data__);
#endif //__POUS_H
