typedef struct K8bService { void (**vtable)(struct K8bService *, char *, int); } K8bService;
struct K8bGlobals { char pad0[116]; K8bService *service; };
typedef struct K8bScreen { void (**vtable)(struct K8bScreen *, int); } K8bScreen;
struct K8bScreens { char pad0[68]; K8bScreen *screen; };
extern struct K8bGlobals *lbl_804b17ec;
extern struct K8bScreens *lbl_804b1788;
extern int w3d_text_format_803442b4(char *buffer, const char *format, ...);

void w3d_k8b_light_names_80157a30(void)
{
    char name[32];
    char *buffer = name;
    unsigned int i;
    K8bService *service;
    void (**table)(K8bService *, char *, int);
    for (i = 0; i <= 15; i++) {
        service = lbl_804b17ec->service;
        table = service->vtable;
        w3d_text_format_803442b4(buffer, "WormLight.%d", i);
        table[49](service, buffer, 4);
        service = lbl_804b17ec->service;
        table = service->vtable;
        w3d_text_format_803442b4(buffer, "WeaponLight.%d", i);
        table[49](service, buffer, 4);
    }
    lbl_804b1788->screen->vtable[22](lbl_804b1788->screen, 4);
}
