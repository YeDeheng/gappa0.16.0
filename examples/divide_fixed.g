i_m = (v_m / r_m);

v_fx = fixed<-8,ne>(v_m);
r_fx = fixed<-8,ne>(r_m);
i_fx fixed<-8,ne> = (v_fx / r_fx);

{ v_m in [1,3.3] /\
  r_m in [1e-2,1e5] ->
  i_fx-i_m in ? /\
  i_fx in ?
}

