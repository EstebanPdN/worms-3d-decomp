// Inferred by-value text ABI and partial handle/property views.
// Only pointer words are accessed. No full external type, allocation size, or unused-word meaning claimed.
extern "C" void fn_8020c5c0(void*),fn_8020c5c4(void*),fn_80341588(void*);
extern "C" unsigned short*fn_80341884(void*);
struct F11aNameText{char*text;F11aNameText(const F11aNameText&o){fn_8020c5c0(this);text=o.text;++*fn_80341884(this);}~F11aNameText(){fn_8020c5c4(this);fn_80341588(this);}};
struct F11aNameIface{void**table;};struct F11aNameHeld{F11aNameIface*p;int unobserved;F11aNameHeld():p(0){}~F11aNameHeld(){if(p)((void(*)(F11aNameIface*))p->table[4])(p);}};
struct F11aNameKey{const char*text;F11aNameKey(const char*p):text(p){}};
extern char key_803d0a54[],key_803d0b88[];
extern "C" int fn_800fc43c(const F11aNameKey&,int),fn_800fc1f0(const F11aNameKey&,int&),fn_802997fc(void*);
extern "C" void fn_80299b48(void*,F11aNameText,bool);
extern "C" void w3d_f11a_apply_team_name_80299520(void*self,F11aNameText name){
 if(!*(unsigned short*)(name.text-4)){F11aNameKey skill(key_803d0a54);fn_800fc43c(skill,0);}
 else{bool changed=false;F11aNameHeld held;changed=fn_802997fc(self)==1;if(changed==true){int permission=0;F11aNameKey key(key_803d0b88);fn_800fc1f0(key,permission);if(permission==1)changed=false;}fn_80299b48(self,name,changed);}
}
