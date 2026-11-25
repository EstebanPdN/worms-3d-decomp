struct R27cEntry { void *first; void *second; unsigned unknown; void *fourth; };
extern int r27c_flag_804b10b0;
extern void *r27c_first_80473724[16];
extern void *r27c_second_80473764[16];
extern R27cEntry r27c_entries_804737a4[16];
extern void *r27c_fourth_804738a4[16];
extern void *r27c_fifth_804738e4[16];
extern "C" void r27c_initialize_802cd308(int initialize, int priority) {
 if (priority == 65535 && initialize) {
  r27c_flag_804b10b0 = 0;
  for (int i=0; i<16; ++i) r27c_first_80473724[i]=0;
  for (int i=0; i<16; ++i) r27c_second_80473764[i]=0;
  for (int i=0; i<16; ++i) { r27c_entries_804737a4[i].first=0; r27c_entries_804737a4[i].second=0; r27c_entries_804737a4[i].fourth=0; }
  for (int i=0; i<16; ++i) r27c_fourth_804738a4[i]=0;
  for (int i=0; i<16; ++i) r27c_fifth_804738e4[i]=0;
 }
}
