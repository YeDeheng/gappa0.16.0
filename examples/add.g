i_m = (v_m + r_m);

v_fx = fixed<-8,zr>(v_m);
r_fx = fixed<-8,zr>(r_m);
i_fx fixed<-7,zr> = (v_fx + r_fx);

{ v_m in [-10,10] /\
  r_m in [-10,10] ->
  i_fx-i_m in ? /\
  i_fx in ?
}

