// Image resampling kernel dispatch. Images remain opaque external GC ABI objects.
struct Sol11bImageView;
typedef float (*Sol11bFilterKernel)(float);
extern "C" {
float kernel_801d6998(float);
float kernel_801d69dc(float);
float kernel_801d6a18(float);
float kernel_801d6a4c(float);
float kernel_801d6aac(float);
float kernel_801d6b7c(float);
float kernel_801d6bf0(float);
extern const float support_803af6c4[];
extern const float support_803af6c8[];
extern const float support_803af6cc[];
extern const float support_803af6d0[];
extern const float support_803af6d4[];
void resample_801d6ca8(Sol11bImageView *, Sol11bImageView *, Sol11bFilterKernel, float);
}
extern "C" void sol11b_filter_select_801d7750(Sol11bImageView *destination, Sol11bImageView *source, unsigned mode)
{
    Sol11bFilterKernel kernel=kernel_801d6998;
    float support=support_803af6c4[0];
    switch(mode) {
    case 0: kernel=kernel_801d69dc; support=support_803af6c8[0]; break;
    case 1: kernel=kernel_801d6a18; break;
    case 2: kernel=kernel_801d6a4c; support=support_803af6cc[0]; break;
    case 3: kernel=kernel_801d6aac; support=support_803af6d0[0]; break;
    case 4: break;
    case 5: kernel=kernel_801d6b7c; support=support_803af6d4[0]; break;
    case 6: kernel=kernel_801d6bf0; support=support_803af6d0[0]; break;
    default: return;
    }
    resample_801d6ca8(destination,source,kernel,support);
}
