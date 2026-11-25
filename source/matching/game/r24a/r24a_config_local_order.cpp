// Inferred configuration layout: word +24 is normalized to the global byte.
struct Configuration { unsigned char unknown[24]; int enabled; };
extern "C" {
extern volatile unsigned char enabled_804ab520;
extern int configuration_804ab51c;
void apply_configuration_8030ba64(int, int, unsigned char);
inline int read_configuration() { return configuration_804ab51c; }
inline unsigned char read_enabled() { return enabled_804ab520; }
inline int selected_channel() { return 1; }
int w3d_r24a_apply_enabled_8016a4f4(void *, Configuration *config)
{
    int value = config->enabled;
    if (value) value = 1;
    enabled_804ab520 = value;
    int channel = configuration_804ab51c; unsigned char flag = enabled_804ab520; apply_configuration_8030ba64(1, channel, flag);
    return 0;
}
}
