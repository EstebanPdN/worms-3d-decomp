// Appears to update four channels: it starts channels whose pending flag is clear once
// the requested time passes their start time, polls started channels, and notifies the
// owner when every channel is idle.
#define VCALL(p, T, o) ((T)(*(void **)(*(char **)(p) + (o))))
extern "C" void w3d_fn_80051930(void *self, int index, int time);
extern "C" void w3d_auto_8015fd1c(void *self);
extern "C" int w3d_k8a_channel_update_8005166c(void *self, int time)
{
    int idle = 1;
    int index = 0;
    int started = 1;
    char *channel = (char *)self + 44;
    int offset = 0;
    do
    {
        void *iface = *(void **)channel;
        if (iface)
        {
            char *flags = (char *)self + 28;
            if (*(int *)(flags + offset) == 0)
            {
                idle = 0;
                if (time > *(int *)(channel + 16))
                {
                    VCALL(iface, void (*)(void *), 20)(iface);
                    *(int *)(flags + offset) = started;
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
