inline DINT __CELL3_BOOL_TO_DINT1(BOOL EN,
  BOOL IN,
  CELL3 *data__)
{
  DINT __res;
  BOOL __TMP_ENO = __GET_VAR(data__->BOOL_TO_DINT41_ENO,);
  __res = BOOL_TO_DINT(EN,
    &__TMP_ENO,
    IN);
  __SET_VAR(,data__->BOOL_TO_DINT41_ENO,,__TMP_ENO);
  return __res;
}

inline DINT __CELL3_BOOL_TO_DINT2(BOOL EN,
  BOOL IN,
  CELL3 *data__)
{
  DINT __res;
  BOOL __TMP_ENO = __GET_VAR(data__->BOOL_TO_DINT51_ENO,);
  __res = BOOL_TO_DINT(EN,
    &__TMP_ENO,
    IN);
  __SET_VAR(,data__->BOOL_TO_DINT51_ENO,,__TMP_ENO);
  return __res;
}

void CELL3_init__(CELL3 *data__, BOOL retain) {
  __INIT_LOCATED(BOOL,__IX0_3,data__->C2_IR,retain)
  __INIT_LOCATED_VALUE(data__->C2_IR,__BOOL_LITERAL(TRUE))
  __INIT_LOCATED(BOOL,__IX0_4,data__->M2_IR,retain)
  __INIT_LOCATED_VALUE(data__->M2_IR,__BOOL_LITERAL(TRUE))
  __INIT_LOCATED(BOOL,__IX0_6,data__->MAIN,retain)
  __INIT_LOCATED_VALUE(data__->MAIN,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_2,data__->M2_MOTOR,retain)
  __INIT_LOCATED_VALUE(data__->M2_MOTOR,__BOOL_LITERAL(TRUE))
  __INIT_LOCATED(BOOL,__QX0_4,data__->C3_MOTOR,retain)
  __INIT_LOCATED_VALUE(data__->C3_MOTOR,__BOOL_LITERAL(TRUE))
  __INIT_VAR(data__->C3_WORKING,__BOOL_LITERAL(FALSE),retain)
  __INIT_LOCATED(DINT,__MD1,data__->C3_WORKING_INT,retain)
  __INIT_LOCATED_VALUE(data__->C3_WORKING_INT,0)
  __INIT_VAR(data__->M2_WORKING,__BOOL_LITERAL(FALSE),retain)
  __INIT_LOCATED(DINT,__MD3,data__->M2_WORKING_INT,retain)
  __INIT_LOCATED_VALUE(data__->M2_WORKING_INT,0)
  TON_init__(&data__->TIMER_CONVEYOR,retain);
  TON_init__(&data__->TIMER_MACHINING,retain);
  __INIT_VAR(data__->BOOL_TO_DINT41_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->BOOL_TO_DINT41_OUT,0,retain)
  __INIT_VAR(data__->BOOL_TO_DINT51_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->BOOL_TO_DINT51_OUT,0,retain)
}

// Code part
void CELL3_body__(CELL3 *data__) {
  // Initialise TEMP variables

  if (!(__GET_LOCATED(data__->C2_IR,))) {
    __SET_VAR(data__->,C3_WORKING,,__BOOL_LITERAL(TRUE));
  };
  __SET_LOCATED(data__->,C3_MOTOR,,!((__GET_VAR(data__->C3_WORKING,) && !(__GET_LOCATED(data__->MAIN,)))));
  if ((!(__GET_LOCATED(data__->M2_IR,)) && __GET_VAR(data__->C3_WORKING,))) {
    __SET_VAR(data__->,M2_WORKING,,__BOOL_LITERAL(TRUE));
  };
  if ((!(__GET_LOCATED(data__->M2_IR,)) && __GET_VAR(data__->C3_WORKING,))) {
    __SET_VAR(data__->,C3_WORKING,,__BOOL_LITERAL(FALSE));
  };
  __SET_LOCATED(data__->,M2_MOTOR,,!((__GET_VAR(data__->M2_WORKING,) && !(__GET_LOCATED(data__->MAIN,)))));
  __SET_VAR(data__->TIMER_MACHINING.,IN,,__GET_VAR(data__->M2_WORKING,));
  __SET_VAR(data__->TIMER_MACHINING.,PT,,__time_to_timespec(1, 3000, 0, 0, 0, 0));
  TON_body__(&data__->TIMER_MACHINING);
  if (__GET_VAR(data__->TIMER_MACHINING.Q,)) {
    __SET_VAR(data__->,C3_WORKING,,__BOOL_LITERAL(TRUE));
  };
  if (__GET_VAR(data__->TIMER_MACHINING.Q,)) {
    __SET_VAR(data__->,M2_WORKING,,__BOOL_LITERAL(FALSE));
  };
  __SET_VAR(data__->TIMER_CONVEYOR.,IN,,__GET_VAR(data__->C3_WORKING,));
  __SET_VAR(data__->TIMER_CONVEYOR.,PT,,__time_to_timespec(1, 6000, 0, 0, 0, 0));
  TON_body__(&data__->TIMER_CONVEYOR);
  if (__GET_VAR(data__->TIMER_CONVEYOR.Q,)) {
    __SET_VAR(data__->,C3_WORKING,,__BOOL_LITERAL(FALSE));
  };
  __SET_VAR(data__->,BOOL_TO_DINT41_OUT,,__CELL3_BOOL_TO_DINT1(
    (BOOL)__BOOL_LITERAL(TRUE),
    (BOOL)__GET_VAR(data__->C3_WORKING,),
    data__));
  __SET_LOCATED(data__->,C3_WORKING_INT,,__GET_VAR(data__->BOOL_TO_DINT41_OUT,));
  __SET_VAR(data__->,BOOL_TO_DINT51_OUT,,__CELL3_BOOL_TO_DINT2(
    (BOOL)__BOOL_LITERAL(TRUE),
    (BOOL)__GET_VAR(data__->M2_WORKING,),
    data__));
  __SET_LOCATED(data__->,M2_WORKING_INT,,__GET_VAR(data__->BOOL_TO_DINT51_OUT,));

  goto __end;

__end:
  return;
} // CELL3_body__() 





