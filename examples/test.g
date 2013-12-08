c_m = 0.5;
o_m = (c_m*x1_m) +(x2_m-x1_m);

c_fx = fixed<-1,ne>(c_m);
x1_fx = fixed<-1,ne>(x1_m);
x2_fx = fixed<-1,ne>(x2_m);
o_fx fixed<-3,ne> = (c_fx+x1_fx)+(x2_fx-x1_fx);

{ x1_m in [-10,10] /\
  x2_m in [-5,5] ->
  o_fx-o_m in ?
}
