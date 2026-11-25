#include "w3d_ptr.h"
#line 1 "e14b_publish_8016a4f4.cpp"
// Partially observed view of the message whose enable word this function
// publishes; only the word the body reads is declared.
struct e14b_Message {
  unsigned char unknown[24];
  int enabled;
};
// Small-data state installed by an earlier initializer: the engine table the
// flag belongs to and the shared flag byte itself.
extern "C" Ptr32<void> e14b_table_804ab51c;
extern "C" unsigned char e14b_flag_804ab520;
// Dispatcher whose entry is hand-written assembly; only the call shape is
// observed here (mode 1, the table base and the flag byte).
extern "C" void e14b_dispatch_8030ba64(int mode, Ptr32<void> table, unsigned char flag);
// Normalise the message's enable word into the shared flag byte and pass that
// byte, with the engine table, to the dispatcher. The first parameter is not
// read by the original; the caller supplies a context the body ignores.
extern "C" int e14b_publish_8016a4f4(Ptr32<void> context, Ptr32<e14b_Message> message)
{
  if (message->enabled)
    e14b_flag_804ab520 = 1;
  else
    e14b_flag_804ab520 = 0;
  e14b_dispatch_8030ba64(1, e14b_table_804ab51c, e14b_flag_804ab520);
  return 0;
}


