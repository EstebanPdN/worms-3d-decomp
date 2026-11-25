struct Z35Rule { unsigned char p0[12]; float multiplier; unsigned char p1[12]; int limit; float rate; };
struct Z35Table { Z35Rule **rules; };
struct Z35Context { unsigned char p[64]; unsigned char disabled; };
struct Z35Settings { unsigned char p[84]; float minimum; unsigned char q[8]; float multiplier; };
struct Z35Scale { float original, value; Z35Scale(float v):original(v),value(v) {} void apply(float factor){ value=original*factor; } };
extern "C" Z35Table *z35_rules_804aa750;
extern "C" Z35Settings *z35_settings_804aa6d8;
extern "C" float z35_zero_80369c48[], z35_one_80369c4c[];
extern "C" float tterra_z35_scale_8000b344(Z35Context *self,int index,float amount,float value) {
 Z35Rule *rule=*(Z35Rule **)((char *)z35_rules_804aa750->rules+(index<<2));
 int capped=0;
 Z35Scale scale(z35_settings_804aa6d8->multiplier);
 float limit=(float)rule->limit;
 if(value>=limit){ capped=1;value=limit;if(value<z35_settings_804aa6d8->minimum)value=z35_settings_804aa6d8->minimum; }
 if(amount!=z35_zero_80369c48[0] && !capped && !self->disabled){
  value=(limit-value)*rule->rate*amount+value;
  scale.apply(rule->rate*amount+z35_one_80369c4c[0]);
  if(value>limit)value=limit;
 }
 return (scale.value*value)*rule->multiplier;
}
