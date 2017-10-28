inline DINT __CELL1_BOOL_TO_DINT1(BOOL EN,
  BOOL IN,
  CELL1 *data__)
{
  DINT __res;
  BOOL __TMP_ENO = __GET_VAR(data__->BOOL_TO_DINT27_ENO,);
  __res = BOOL_TO_DINT(EN,
    &__TMP_ENO,
    IN);
  __SET_VAR(,data__->BOOL_TO_DINT27_ENO,,__TMP_ENO);
  return __res;
}

inline DINT __CELL1_BOOL_TO_DINT2(BOOL EN,
  BOOL IN,
  CELL1 *data__)
{
  DINT __res;
  BOOL __TMP_ENO = __GET_VAR(data__->BOOL_TO_DINT37_ENO,);
  __res = BOOL_TO_DINT(EN,
    &__TMP_ENO,
    IN);
  __SET_VAR(,data__->BOOL_TO_DINT37_ENO,,__TMP_ENO);
  return __res;
}

inline DINT __CELL1_BOOL_TO_DINT3(BOOL EN,
  BOOL IN,
  CELL1 *data__)
{
  DINT __res;
  BOOL __TMP_ENO = __GET_VAR(data__->BOOL_TO_DINT61_ENO,);
  __res = BOOL_TO_DINT(EN,
    &__TMP_ENO,
    IN);
  __SET_VAR(,data__->BOOL_TO_DINT61_ENO,,__TMP_ENO);
  return __res;
}

inline DINT __CELL1_BOOL_TO_DINT4(BOOL EN,
  BOOL IN,
  CELL1 *data__)
{
  DINT __res;
  BOOL __TMP_ENO = __GET_VAR(data__->BOOL_TO_DINT67_ENO,);
  __res = BOOL_TO_DINT(EN,
    &__TMP_ENO,
    IN);
  __SET_VAR(,data__->BOOL_TO_DINT67_ENO,,__TMP_ENO);
  return __res;
}

void CELL1_init__(CELL1 *data__, BOOL retain) {
  __INIT_LOCATED(BOOL,__IX0_2,data__->R1_FRONT,retain)
  __INIT_LOCATED_VALUE(data__->R1_FRONT,__BOOL_LITERAL(TRUE))
  __INIT_LOCATED(BOOL,__IX0_3,data__->R1_REAR,retain)
  __INIT_LOCATED_VALUE(data__->R1_REAR,__BOOL_LITERAL(TRUE))
  __INIT_LOCATED(BOOL,__IX0_4,data__->C1_ENDIR,retain)
  __INIT_LOCATED_VALUE(data__->C1_ENDIR,__BOOL_LITERAL(TRUE))
  __INIT_LOCATED(BOOL,__IX0_5,data__->C1_STARTIR,retain)
  __INIT_LOCATED_VALUE(data__->C1_STARTIR,__BOOL_LITERAL(TRUE))
  __INIT_LOCATED(BOOL,__IX0_6,data__->MAIN,retain)
  __INIT_LOCATED_VALUE(data__->MAIN,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_2,data__->R1_FWD_MOTOR,retain)
  __INIT_LOCATED_VALUE(data__->R1_FWD_MOTOR,__BOOL_LITERAL(TRUE))
  __INIT_LOCATED(BOOL,__QX0_3,data__->R1_BWD_MOTOR,retain)
  __INIT_LOCATED_VALUE(data__->R1_BWD_MOTOR,__BOOL_LITERAL(TRUE))
  __INIT_LOCATED(BOOL,__QX0_4,data__->C1_MOTOR,retain)
  __INIT_LOCATED_VALUE(data__->C1_MOTOR,__BOOL_LITERAL(TRUE))
  __INIT_VAR(data__->C1_WORKING,__BOOL_LITERAL(FALSE),retain)
  __INIT_LOCATED(DINT,__MD1,data__->C1_WORKING_INT,retain)
  __INIT_LOCATED_VALUE(data__->C1_WORKING_INT,0)
  __INIT_VAR(data__->R1_IN_TRANSIT,__BOOL_LITERAL(FALSE),retain)
  __INIT_LOCATED(DINT,__MD3,data__->R1_IN_TRANSIT_INT,retain)
  __INIT_LOCATED_VALUE(data__->R1_IN_TRANSIT_INT,0)
  __INIT_VAR(data__->R1_FWD,__BOOL_LITERAL(FALSE),retain)
  __INIT_LOCATED(DINT,__MD4,data__->R1_FWD_INT,retain)
  __INIT_LOCATED_VALUE(data__->R1_FWD_INT,0)
  __INIT_VAR(data__->R1_BWD,__BOOL_LITERAL(FALSE),retain)
  __INIT_LOCATED(DINT,__MD5,data__->R1_BWD_INT,retain)
  __INIT_LOCATED_VALUE(data__->R1_BWD_INT,0)
  TON_init__(&data__->TIMER_IN_TRANSIT,retain);
  __INIT_VAR(data__->BOOL_TO_DINT27_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->BOOL_TO_DINT27_OUT,0,retain)
  __INIT_VAR(data__->BOOL_TO_DINT37_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->BOOL_TO_DINT37_OUT,0,retain)
  __INIT_VAR(data__->BOOL_TO_DINT61_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->BOOL_TO_DINT61_OUT,0,retain)
  __INIT_VAR(data__->BOOL_TO_DINT67_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->BOOL_TO_DINT67_OUT,0,retain)
}

// Code part
void CELL1_body__(CELL1 *data__) {
  // Initialise TEMP variables
  if (!(__GET_LOCATED(data__->C1_STARTIR,))) {
    __SET_VAR(data__->,C1_WORKING,,__BOOL_LITERAL(TRUE));
  };
  __SET_LOCATED(data__->,C1_MOTOR,,!((__GET_VAR(data__->C1_WORKING,) && !(__GET_LOCATED(data__->MAIN,)))));
  if (!(__GET_LOCATED(data__->C1_ENDIR,))) {
    __SET_VAR(data__->,R1_IN_TRANSIT,,__BOOL_LITERAL(TRUE));
  };
  __SET_VAR(data__->TIMER_IN_TRANSIT.,IN,,(__GET_VAR(data__->R1_IN_TRANSIT,) && __GET_VAR(data__->C1_WORKING,)));
  __SET_VAR(data__->TIMER_IN_TRANSIT.,PT,,__time_to_timespec(1, 1000, 0, 0, 0, 0));
  TON_body__(&data__->TIMER_IN_TRANSIT);
  if (__GET_VAR(data__->TIMER_IN_TRANSIT.Q,)) {
    __SET_VAR(data__->,R1_FWD,,__BOOL_LITERAL(TRUE));
  };
  if (__GET_VAR(data__->TIMER_IN_TRANSIT.Q,)) {
    __SET_VAR(data__->,C1_WORKING,,__BOOL_LITERAL(FALSE));
  };
  if (__GET_VAR(data__->TIMER_IN_TRANSIT.Q,)) {
    __SET_VAR(data__->,R1_IN_TRANSIT,,__BOOL_LITERAL(FALSE));
  };
  __SET_LOCATED(data__->,R1_FWD_MOTOR,,!((__GET_VAR(data__->R1_FWD,) && !(__GET_LOCATED(data__->MAIN,)))));
  if ((!(__GET_LOCATED(data__->R1_FRONT,)) && __GET_VAR(data__->R1_FWD,))) {
    __SET_VAR(data__->,R1_BWD,,__BOOL_LITERAL(TRUE));
  };
  if ((!(__GET_LOCATED(data__->R1_FRONT,)) && __GET_VAR(data__->R1_FWD,))) {
    __SET_VAR(data__->,R1_FWD,,__BOOL_LITERAL(FALSE));
  };
  __SET_LOCATED(data__->,R1_BWD_MOTOR,,!((__GET_VAR(data__->R1_BWD,) && !(__GET_LOCATED(data__->MAIN,)))));
  if ((!(__GET_LOCATED(data__->R1_REAR,)) && __GET_VAR(data__->R1_BWD,))) {
    __SET_VAR(data__->,R1_BWD,,__BOOL_LITERAL(FALSE));
  };
  __SET_VAR(data__->,BOOL_TO_DINT27_OUT,,__CELL1_BOOL_TO_DINT1(
    (BOOL)__BOOL_LITERAL(TRUE),
    (BOOL)__GET_VAR(data__->C1_WORKING,),
    data__));
  __SET_LOCATED(data__->,C1_WORKING_INT,,__GET_VAR(data__->BOOL_TO_DINT27_OUT,));
  __SET_VAR(data__->,BOOL_TO_DINT37_OUT,,__CELL1_BOOL_TO_DINT2(
    (BOOL)__BOOL_LITERAL(TRUE),
    (BOOL)__GET_VAR(data__->R1_IN_TRANSIT,),
    data__));
  __SET_LOCATED(data__->,R1_IN_TRANSIT_INT,,__GET_VAR(data__->BOOL_TO_DINT37_OUT,));
  __SET_VAR(data__->,BOOL_TO_DINT61_OUT,,__CELL1_BOOL_TO_DINT3(
    (BOOL)__BOOL_LITERAL(TRUE),
    (BOOL)__GET_VAR(data__->R1_FWD,),
    data__));
  __SET_LOCATED(data__->,R1_FWD_INT,,__GET_VAR(data__->BOOL_TO_DINT61_OUT,));
  __SET_VAR(data__->,BOOL_TO_DINT67_OUT,,__CELL1_BOOL_TO_DINT4(
    (BOOL)__BOOL_LITERAL(TRUE),
    (BOOL)__GET_VAR(data__->R1_BWD,),
    data__));
  __SET_LOCATED(data__->,R1_BWD_INT,,__GET_VAR(data__->BOOL_TO_DINT67_OUT,));

  goto __end;

__end:
  return;
} // CELL1_body__() 





