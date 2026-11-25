
// Shared string: base calls and count header are observed, names inferred.
struct Cx16cString;
extern "C" void cx16c_string_init_8020c5c0(Cx16cString*);
extern "C" unsigned short *cx16c_string_header_80341884(Cx16cString*);
extern "C" void cx16c_string_finish_8020c5c4(Cx16cString*);
extern "C" void cx16c_string_release_80341588(Cx16cString*);
struct Cx16cString {
 const char *data;
 Cx16cString(const Cx16cString &other) {
  cx16c_string_init_8020c5c0(this); data=other.data; ++*cx16c_string_header_80341884(this);
 }
 ~Cx16cString() { cx16c_string_finish_8020c5c4(this);cx16c_string_release_80341588(this); }
};
struct Cx16cHeld { void **methods; };
struct Cx16cTextPanel { char reserved[36]; Cx16cHeld *held; char gap[32]; int value; int reserved76; int mode; };
extern "C" int cx16c_set_text_802c196c(Cx16cTextPanel*,Cx16cString);
extern "C" int cx16c_refresh_802c17bc(Cx16cTextPanel*);
extern "C" void cx16c_notify_802c14fc(Cx16cTextPanel*);
extern "C" void w3d_cx16c_panel_apply_text_802c1bd8(Cx16cTextPanel *self,Cx16cString text,int value,int mode) {
 self->value=value;
 self->mode=mode;
 if(mode==1) {
  if(self->held) ((void(*)(Cx16cHeld*))self->held->methods[4])(self->held);
  self->held=0;
 }
 cx16c_set_text_802c196c(self,text);
 cx16c_refresh_802c17bc(self);
 cx16c_notify_802c14fc(self);
}
