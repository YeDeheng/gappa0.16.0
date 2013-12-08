i_m = (v_m / r_m);

v_fx = fixed<-4,ne>(v_m);
r_fx = fixed<-4,ne>(r_m);
i_fx float<ieee_32,ne> = (v_fx / r_fx);

{ v_m in [0,3.3] /\
  r_m in [1e-3,1e5] ->
  i_fx-i_m in ? /\
  i_fx in ?
}

