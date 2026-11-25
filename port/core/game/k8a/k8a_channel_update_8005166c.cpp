#include "w3d_ptr.h"
#line 1 "k8a_channel_update_8005166c.cpp"
// Appears to update four channels: it starts channels whose pending flag is clear once
// the requested time passes their start time, polls started channels, and notifies the
// owner when every channel is idle.
#define VCALL(p, T, o) ((w3d::slot_t<T>)(*(Ptr32<void> *)w3d::AG(*(Ptr32<char> *)w3d::AG(p) + (o))))
extern "C" void w3d_fn_80051930(Ptr32<void> self, int index, int time);
extern "C" void w3d_auto_8015fd1c(Ptr32<void> self);
extern "C" int w3d_k8a_channel_update_8005166c(Ptr32<void> self, int time)
{
    int idle = 1;
    int index = 0;
    int started = 1;
    Ptr32<char> channel = (Ptr32<char>)self + 44;
    int offset = 0;
    do
    {
        Ptr32<void> iface = *(Ptr32<Ptr32<void>>)channel;
        if (iface)
        {
            Ptr32<char> flags = (Ptr32<char>)self + 28;
            if (*(Ptr32<int>)(flags + offset) == 0)
            {
                idle = 0;
                if (time > *(Ptr32<int>)(channel + 16))
                {
                    VCALL(iface, void (*)(void *), 20)(iface);
                    *(Ptr32<int>)(flags + offset) = started;
                }
            }
            else if (VCALL(iface, int (*)(void *), 36)(iface))
            {
                idle = 0;
                w3d_fn_80051930(self, index, time);
            }
        }
        index++;
        channel += 4;
        offset += 4;
    } while (index <= 3);
    if (idle)
        w3d_auto_8015fd1c(self);
    return 0;
}


