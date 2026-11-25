struct K6bService { void **vtable; };
extern struct K6bService *w3d_auto_8020b648(void);
extern char lbl_80419500[];
int w3d_k6b_service_copy_setting_8020ed40(void)
{
    char *key = lbl_80419500;
    struct K6bService *service = w3d_auto_8020b648();
    int value = ((int (*)(struct K6bService *, char *))service->vtable[23])(service, key);
    service = w3d_auto_8020b648();
    ((void (*)(struct K6bService *, char *, int))service->vtable[25])(service, key, value);
    return 0;
}
// desc: w3d_k6b_service_copy_setting_8020ed40: Appears to read the setting named by 0x80419500 through virtual slot 23 of the 0x8020b648 service and write it back through slot 25.
