@fx = fixed<-16,ne>;

v_m = float<ieee_64,ne>(v);
isat_m = float<ieee_64,ne>(1e-3);
vj_m = float<ieee_64,ne>(0.0258642);

i_m = isat_m*(exp(v_m/vj_m)-1);
g_m = isat_m*exp(v_m/vj_m)/vj_m;

isat_fl = float<ieee_32,ne>(isat_m);
vj_fl = float<ieee_32,ne>(vj_m);
g_fl float<ieee_32,ne> = isat_fl*exp(v_m/vj_fl)/vj_fl;
i_fl float<ieee_32,ne> = isat_fl*(exp(v_m/vj_fl)-1)-g_fl*v_m;

isat_dbl = float<ieee_64,ne>(isat_m);
vj_dbl = float<ieee_64,ne>(vj_m);
g_dbl float<ieee_64,ne> = isat_dbl*exp(v_m/vj_m)/vj_dbl;
i_dbl float<ieee_64,ne> = isat_dbl*(exp(v_m/vj_m)-1)-g_dbl*v_m;

isat_fx = fx(isat_m);
vj_fx = fx(vj_m);
v_fx = fx(v);
g_fx fx = isat_fx*exp(v_fx/vj_fx)/vj_fx;
i_fx fx = isat_fx*(exp(v_fx/vj_fx)-1)-g_fx*v_fx;

{
	v in [0,0.1] ->
	i_dbl-i_fx in ? /\
	g_dbl-g_fx in ?
}

#	i_dbl-i_fx in [-1e-8,1e-8] /\
#	i_dbl in [0,1] /\
#	g_m in ? /\
#	g_dbl in ? /\
#	g_dbl-float<ieee_64,ne>(g_m) in ?
#	i_m in ? /\
#	i_fl-float<ieee_32,ne>(i_m) in ? /\
#	g_fl-g_m in ? /\
#	g_dbl-g_m in ? /\
#	i_dbl-i_fl in ? /\
#	g_dbl-g_fl in ? /\
#	i_fx-i_m in ? /\
#	g_fx-g_m in ? /\
#	i_fl-i_fx in ? /\
#	g_fl-g_fx in ?
#}

#i_dbl $ v;
#i_dbl-i_fx $ v;
