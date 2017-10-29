void SCENE1_init__(SCENE1 *data__, BOOL retain) {
  __INIT_LOCATED(BOOL,__IX0_0,data__->SENSOR,retain)
  __INIT_LOCATED_VALUE(data__->SENSOR,__BOOL_LITERAL(TRUE))
  __INIT_LOCATED(BOOL,__QX0_0,data__->CONV_BELT,retain)
  __INIT_LOCATED_VALUE(data__->CONV_BELT,__BOOL_LITERAL(TRUE))
}

// Code part
void SCENE1_body__(SCENE1 *data__) {
  // Initialise TEMP variables

  __SET_LOCATED(data__->,CONV_BELT,,__GET_LOCATED(data__->SENSOR,));

  goto __end;

__end:
  return;
} // SCENE1_body__() 





