/* Observed named-property notifications for three reels. */
extern "C" {
struct ReelString { char *text; int reserved; };
struct ReelConfig { char pad[144]; char *third; char *second; char *first; };
struct ReelWidget { char pad[40]; ReelConfig *config; char gap[180]; int busy; int values[3]; char gap2[1088]; int targets[3]; unsigned flags; };
void w3d_string_base_init(ReelString *);
unsigned short *w3d_string_header(ReelString *);
int w3d_fn_802aa5f0(ReelWidget *,ReelString *);
int w3d_fn_802ab378(ReelWidget *,int,int);
int w3d_s4_wormpot_first_changed(void *,ReelWidget *self)
{
    if(!self->busy) {
        ReelString text;
        register ReelString *value=&text;
        ReelConfig *config=self->config;
        w3d_string_base_init(value);
        text.text=config->first;
        register unsigned short *header=w3d_string_header(value);
        ++*header;
        int current=w3d_fn_802aa5f0(self,value);
        self->values[0]=current;
        int index=w3d_fn_802ab378(self,0,current);
        self->flags &= ~0x2000U;
        if(index<0) index=0;
        self->targets[0]=index;
        self->flags |= 0x10000U;
    }
    return 0;
}
int w3d_s4_wormpot_second_changed(void *,ReelWidget *self)
{
    if(!self->busy) {
        ReelString text;
        register ReelString *value=&text;
        ReelConfig *config=self->config;
        w3d_string_base_init(value);
        text.text=config->second;
        register unsigned short *header=w3d_string_header(value);
        ++*header;
        int current=w3d_fn_802aa5f0(self,value);
        self->values[1]=current;
        int index=w3d_fn_802ab378(self,1,current);
        self->flags &= ~0x2000U;
        if(index<0) index=0;
        self->targets[1]=index;
        self->flags |= 0x20000U;
    }
    return 0;
}
int w3d_s4_wormpot_third_changed(void *,ReelWidget *self)
{
    if(!self->busy) {
        ReelString text;
        register ReelString *value=&text;
        ReelConfig *config=self->config;
        w3d_string_base_init(value);
        text.text=config->third;
        register unsigned short *header=w3d_string_header(value);
        ++*header;
        int current=w3d_fn_802aa5f0(self,value);
        self->values[2]=current;
        int index=w3d_fn_802ab378(self,2,current);
        self->flags &= ~0x2000U;
        if(index<0) index=0;
        self->targets[2]=index;
        self->flags |= 0x40000U;
    }
    return 0;
}
}
