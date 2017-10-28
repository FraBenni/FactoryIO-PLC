PROGRAM Scene1
  VAR
    sensor AT %IX0.0 : BOOL := true;
    conv_belt AT %QX0.0 : BOOL := true;
  END_VAR

  conv_belt := sensor;
END_PROGRAM


CONFIGURATION Config

  RESOURCE Res ON PLC
    TASK TaskMain(INTERVAL := T#50ms,PRIORITY := 0);
    PROGRAM Inst WITH TaskMain : Scene1;
  END_RESOURCE
END_CONFIGURATION
