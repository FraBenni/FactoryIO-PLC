inline DINT __CELL4_BOOL_TO_DINT1(BOOL EN,
  BOOL IN,
  CELL4 *data__)
{
  DINT __res;
  BOOL __TMP_ENO = __GET_VAR(data__->BOOL_TO_DINT49_ENO,);
  __res = BOOL_TO_DINT(EN,
    &__TMP_ENO,
    IN);
  __SET_VAR(,data__->BOOL_TO_DINT49_ENO,,__TMP_ENO);
  return __res;
}

inline DINT __CELL4_BOOL_TO_DINT2(BOOL EN,
  BOOL IN,
  CELL4 *data__)
{
  DINT __res;
  BOOL __TMP_ENO = __GET_VAR(data__->BOOL_TO_DINT64_ENO,);
  __res = BOOL_TO_DINT(EN,
    &__TMP_ENO,
    IN);
  __SET_VAR(,data__->BOOL_TO_DINT64_ENO,,__TMP_ENO);
  return __res;
}

inline DINT __CELL4_BOOL_TO_DINT3(BOOL EN,
  BOOL IN,
  CELL4 *data__)
{
  DINT __res;
  BOOL __TMP_ENO = __GET_VAR(data__->BOOL_TO_DINT61_ENO,);
  __res = BOOL_TO_DINT(EN,
    &__TMP_ENO,
    IN);
  __SET_VAR(,data__->BOOL_TO_DINT61_ENO,,__TMP_ENO);
  return __res;
}

inline DINT __CELL4_BOOL_TO_DINT4(BOOL EN,
  BOOL IN,
  CELL4 *data__)
{
  DINT __res;
  BOOL __TMP_ENO = __GET_VAR(data__->BOOL_TO_DINT67_ENO,);
  __res = BOOL_TO_DINT(EN,
    &__TMP_ENO,
    IN);
  __SET_VAR(,data__->BOOL_TO_DINT67_ENO,,__TMP_ENO);
  return __res;
}

void CELL4_init__(CELL4 *data__, BOOL retain) {
  __INIT_LOCATED(BOOL,__IX0_2,data__->R2_FRONT,retain)
  __INIT_LOCATED_VALUE(data__->R2_FRONT,__BOOL_LITERAL(TRUE))
  __INIT_LOCATED(BOOL,__IX0_3,data__->R2_REAR,retain)
  __INIT_LOCATED_VALUE(data__->R2_REAR,__BOOL_LITERAL(TRUE))
  __INIT_LOCATED(BOOL,__IX0_4,data__->C4_ENDIR,retain)
  __INIT_LOCATED_VALUE(data__->C4_ENDIR,__BOOL_LITERAL(TRUE))
  __INIT_LOCATED(BOOL,__IX0_5,data__->C3_IR,retain)
  __INIT_LOCATED_VALUE(data__->C3_IR,__BOOL_LITERAL(TRUE))
  __INIT_LOCATED(BOOL,__IX0_6,data__->MAIN,retain)
  __INIT_LOCATED_VALUE(data__->MAIN,__BOOL_LITERAL(FALSE))
  __INIT_LOCATED(BOOL,__QX0_2,data__->R2_FWD_MOTOR,retain)
  __INIT_LOCATED_VALUE(data__->R2_FWD_MOTOR,__BOOL_LITERAL(TRUE))
  __INIT_LOCATED(BOOL,__QX0_3,data__->R2_BWD_MOTOR,retain)
  __INIT_LOCATED_VALUE(data__->R2_BWD_MOTOR,__BOOL_LITERAL(TRUE))
  __INIT_LOCATED(BOOL,__QX0_4,data__->C4_MOTOR,retain)
  __INIT_LOCATED_VALUE(data__->C4_MOTOR,__BOOL_LITERAL(TRUE))
  __INIT_VAR(data__->C4_WORKING,__BOOL_LITERAL(FALSE),retain)
  __INIT_LOCATED(DINT,__MD1,data__->C4_WORKING_INT,retain)
  __INIT_LOCATED_VALUE(data__->C4_WORKING_INT,0)
  __INIT_VAR(data__->R2_IN_TRANSIT,__BOOL_LITERAL(FALSE),retain)
  __INIT_LOCATED(DINT,__MD3,data__->R2_IN_TRANSIT_INT,retain)
  __INIT_LOCATED_VALUE(data__->R2_IN_TRANSIT_INT,0)
  __INIT_VAR(data__->R2_FWD,__BOOL_LITERAL(FALSE),retain)
  __INIT_LOCATED(DINT,__MD4,data__->R2_FWD_INT,retain)
  __INIT_LOCATED_VALUE(data__->R2_FWD_INT,0)
  __INIT_VAR(data__->R2_BWD,__BOOL_LITERAL(FALSE),retain)
  __INIT_LOCATED(DINT,__MD5,data__->R2_BWD_INT,retain)
  __INIT_LOCATED_VALUE(data__->R2_BWD_INT,0)
  TON_init__(&data__->TIMER_IN_TRANSIT,retain);
  __INIT_VAR(data__->BOOL_TO_DINT49_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->BOOL_TO_DINT49_OUT,0,retain)
  __INIT_VAR(data__->BOOL_TO_DINT64_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->BOOL_TO_DINT64_OUT,0,retain)
  __INIT_VAR(data__->BOOL_TO_DINT61_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->BOOL_TO_DINT61_OUT,0,retain)
  __INIT_VAR(data__->BOOL_TO_DINT67_ENO,__BOOL_LITERAL(FALSE),retain)
  __INIT_VAR(data__->BOOL_TO_DINT67_OUT,0,retain)
}

// Code part
void CELL4_body__(CELL4 *data__) {
  // Initialise TEMP variables
  
  if (!(__GET_LOCATED(data__->C3_IR,))) {
    __SET_VAR(data__->,R2_IN_TRANSIT,,__BOOL_LITERAL(TRUE));
  };
  __SET_VAR(data__->TIMER_IN_TRANSIT.,IN,,__GET_VAR(data__->R2_IN_TRANSIT,));
  __SET_VAR(data__->TIMER_IN_TRANSIT.,PT,,__time_to_timespec(1, 4500, 0, 0, 0, 0));
  TON_body__(&data__->TIMER_IN_TRANSIT);
  if (__GET_VAR(data__->TIMER_IN_TRANSIT.Q,)) {
    __SET_VAR(data__->,R2_FWD,,__BOOL_LITERAL(TRUE));
  };
  if (__GET_VAR(data__->TIMER_IN_TRANSIT.Q,)) {
    __SET_VAR(data__->,C4_WORKING,,__BOOL_LITERAL(TRUE));
  };
  if (__GET_VAR(data__->TIMER_IN_TRANSIT.Q,)) {
    __SET_VAR(data__->,R2_IN_TRANSIT,,__BOOL_LITERAL(FALSE));
  };
  __SET_LOCATED(data__->,R2_FWD_MOTOR,,!((__GET_VAR(data__->R2_FWD,) && !(__GET_LOCATED(data__->MAIN,)))));
  if ((!(__GET_LOCATED(data__->R2_FRONT,)) && __GET_VAR(data__->R2_FWD,))) {
    __SET_VAR(data__->,R2_BWD,,__BOOL_LITERAL(TRUE));
  };
  if ((!(__GET_LOCATED(data__->R2_FRONT,)) && __GET_VAR(data__->R2_FWD,))) {
    __SET_VAR(data__->,R2_FWD,,__BOOL_LITERAL(FALSE));
  };
  __SET_LOCATED(data__->,R2_BWD_MOTOR,,!(((__GET_VAR(data__->R2_BWD,) && !(__GET_LOCATED(data__->MAIN,))) && __BOOL_LITERAL(TRUE))));
  if ((!(__GET_LOCATED(data__->R2_REAR,)) && __GET_VAR(data__->R2_BWD,))) {
    __SET_VAR(data__->,R2_BWD,,__BOOL_LITERAL(FALSE));
  };
  __SET_LOCATED(data__->,C4_MOTOR,,!((__GET_VAR(data__->C4_WORKING,) && !(__GET_LOCATED(data__->MAIN,)))));
  if ((!(__GET_LOCATED(data__->C4_ENDIR,)) && __GET_VAR(data__->C4_WORKING,))) {
    __SET_VAR(data__->,C4_WORKING,,__BOOL_LITERAL(FALSE));
  };
  __SET_VAR(data__->,BOOL_TO_DINT49_OUT,,__CELL4_BOOL_TO_DINT1(
    (BOOL)__BOOL_LITERAL(TRUE),
    (BOOL)__GET_VAR(data__->C4_WORKING,),
    data__));
  __SET_LOCATED(data__->,C4_WORKING_INT,,__GET_VAR(data__->BOOL_TO_DINT49_OUT,));
  __SET_VAR(data__->,BOOL_TO_DINT64_OUT,,__CELL4_BOOL_TO_DINT2(
    (BOOL)__BOOL_LITERAL(TRUE),
    (BOOL)__GET_VAR(data__->R2_IN_TRANSIT,),
    data__));
  __SET_LOCATED(data__->,R2_IN_TRANSIT_INT,,__GET_VAR(data__->BOOL_TO_DINT64_OUT,));
  __SET_VAR(data__->,BOOL_TO_DINT61_OUT,,__CELL4_BOOL_TO_DINT3(
    (BOOL)__BOOL_LITERAL(TRUE),
    (BOOL)__GET_VAR(data__->R2_FWD,),
    data__));
  __SET_LOCATED(data__->,R2_FWD_INT,,__GET_VAR(data__->BOOL_TO_DINT61_OUT,));
  __SET_VAR(data__->,BOOL_TO_DINT67_OUT,,__CELL4_BOOL_TO_DINT4(
    (BOOL)__BOOL_LITERAL(TRUE),
    (BOOL)__GET_VAR(data__->R2_BWD,),
    data__));
  __SET_LOCATED(data__->,R2_BWD_INT,,__GET_VAR(data__->BOOL_TO_DINT67_OUT,));

  goto __end;

__end:
  return;
} // CELL4_body__() 





