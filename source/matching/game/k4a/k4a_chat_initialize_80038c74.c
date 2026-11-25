typedef struct K4aString { char *text; } K4aString;
typedef struct K4aChat { char pad0[20]; unsigned int owner; char pad1[4]; void *service; void *messages; int first; int second; K4aString private_prefix; K4aString ally_prefix; K4aString anon_prefix; } K4aChat;
extern char w3d_str_8037400c[];
extern char w3d_str_8037401c[];
extern char w3d_str_80374024[];
extern char w3d_str_8037402c[];
extern char w3d_service_8040e640[];
extern void *w3d_context_804b178c;
extern int w3d_constructor_lookup_name(const char **name, void **output);
extern void *w3d_s10_service_forward_8020b680(void *type);
extern void *FUN_80164514(void *context, void *service, unsigned int owner);
extern void w3d_string_assign(K4aString *string, const char *text);
extern void w3d_auto_80038d1c(K4aChat *self);

void k4a_chat_initialize_80038c74(K4aChat *self)
{
    const char *name;
    void *service;
    name = w3d_str_8037400c;
    w3d_constructor_lookup_name(&name, &self->messages);
    service = w3d_s10_service_forward_8020b680(w3d_service_8040e640);
    self->service = FUN_80164514(w3d_context_804b178c, service, self->owner);
    self->first = 0;
    self->second = 0;
    w3d_string_assign(&self->private_prefix, w3d_str_8037401c);
    w3d_string_assign(&self->ally_prefix, w3d_str_80374024);
    w3d_string_assign(&self->anon_prefix, w3d_str_8037402c);
    w3d_auto_80038d1c(self);
}
