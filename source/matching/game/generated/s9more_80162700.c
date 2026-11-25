/* Instances of a hand-matched template written by tools/gen_param_units.py and
 * verified identical to the original after linking. Offsets, constants and
 * address-named externs differ per instance; names are structural. */

/* Structural family templates; only observed fields and calls are named. */
#define FIELD(p,T,o) (*(T *)((char *)(p) + (o)))
typedef int (*S9Method)(void *);
typedef void (*S9VoidMethod)(void *);
typedef unsigned char *(*S9ByteMethod)(void *);
typedef int (*S9SubmitMethod)(void *, void *, int, int, int);
extern unsigned short lbl_804b18a4;
extern char *lbl_804b189c;
extern int fn_80185b0c(void *);
extern int fn_80185b24(void *);
extern int fn_80178b5c(void *,int);
typedef struct S9PropertyHeader { char unknown0[4]; unsigned short kind; char unknown6[18]; int count; unsigned short refs; char unknown30[2]; char data[1]; } S9PropertyHeader;
extern void *fn_801ef048(void *,int,int,int);
extern int fn_80177eb0(void *,void *,unsigned short *);
extern void *fn_803426b4(void *);
extern void *fn_80178c48(void *);
extern unsigned short lbl_804ab58c;
extern char *lbl_804ab588;
extern unsigned short lbl_804ab610;
extern char *lbl_804ab60c;
extern unsigned short lbl_804ab684;
extern char *lbl_804ab680;

int s9_release_reference_80162700(void *self)
{
    int remaining=--FIELD(self,int,12);
    if(!remaining)FIELD(FIELD(self,void *,0),S9VoidMethod,20)(self);
    return remaining;
}

void s9_count_pool_categories_80170b2c(int *counts)
{
    unsigned short i;
    for(i=0;i<lbl_804b18a4;i++) {
        if(fn_80185b0c(lbl_804b189c+i*136)) {
            fn_80185b24(lbl_804b189c+i*136)[counts]++;
        }
    }
}

unsigned char s9_virtual_byte_801734d0(void *self)
{
    void *inner=FIELD(self,void *,116);
    return *FIELD(FIELD(inner,void *,0),S9ByteMethod,72)(inner);
}

void s9_count_pool_categories_8017453c(int *counts)
{
    unsigned short i;
    for(i=0;i<lbl_804ab58c;i++) {
        if(fn_80185b0c(lbl_804ab588+i*172)) {
            fn_80185b24(lbl_804ab588+i*172)[counts]++;
        }
    }
}

unsigned char s9_virtual_byte_80175044(void *self)
{
    void *inner=FIELD(self,void *,116);
    return *FIELD(FIELD(inner,void *,0),S9ByteMethod,72)(inner);
}

int s9_submit_descriptors_80175f7c(void *owner,char *descriptors,unsigned int count)
{
    int last_error=0;
    unsigned int i;
    for(i=0;i<count;i++) {
        char *entry=descriptors+i*16;
        int result = FIELD(FIELD(owner,void *,0),S9SubmitMethod,36)(owner,entry,FIELD(entry,int,12),FIELD(entry,unsigned char,4),FIELD(entry,int,8));
        if(result<0)last_error=result;
    }
    return last_error;
}

int s9_submit_descriptors_80176000(void *owner,char *descriptors,unsigned int count)
{
    int last_error=0;
    unsigned int i;
    for(i=0;i<count;i++) {
        char *entry=descriptors+i*16;
        int result = FIELD(FIELD(owner,void *,0),S9SubmitMethod,40)(owner,entry,FIELD(entry,int,12),FIELD(entry,unsigned char,4),FIELD(entry,int,8));
        if(result<0)last_error=result;
    }
    return last_error;
}

int s9_submit_descriptors_801761a4(void *owner,char *descriptors,unsigned int count)
{
    int last_error=0;
    unsigned int i;
    for(i=0;i<count;i++) {
        char *entry=descriptors+i*16;
        int result = FIELD(FIELD(owner,void *,0),S9SubmitMethod,52)(owner,entry,FIELD(entry,int,12),FIELD(entry,unsigned char,4),FIELD(entry,int,8));
        if(result<0)last_error=result;
    }
    return last_error;
}

int s9_release_reference_80178884(void *self)
{
    int remaining=--FIELD(self,int,20);
    if(!remaining)FIELD(FIELD(self,void *,0),S9VoidMethod,20)(self);
    return remaining;
}

int s9_update_value_80178c54(void *self,const int *value)
{
    void *inner=FIELD(self,void *,4);
    int v=*value;
    if(FIELD(inner,int,28)==v)return 1;
    FIELD(inner,int,28)=v;
    fn_80178b5c(self,v);
    return 0;
}

int s9_update_value_80178d28(void *self,const int *value)
{
    void *inner=FIELD(self,void *,4);
    int v=*value;
    if(FIELD(inner,int,28)==v)return 1;
    FIELD(inner,int,28)=v;
    fn_80178b5c(self,v);
    return 0;
}

int s9_update_value_80178f60(void *self,const int *value)
{
    void *inner=FIELD(self,void *,4);
    int v=*value;
    if(FIELD(inner,int,28)==v)return 1;
    FIELD(inner,int,28)=v;
    fn_80178b5c(self,v);
    return 0;
}

int s9_release_reference_80179800(void *self)
{
    int remaining=--FIELD(self,int,16);
    if(!remaining)FIELD(FIELD(self,void *,0),S9VoidMethod,20)(self);
    return remaining;
}

void s9_count_pool_categories_8017f540(int *counts)
{
    unsigned short i;
    for(i=0;i<lbl_804ab610;i++) {
        if(fn_80185b0c(lbl_804ab60c+i*204)) {
            fn_80185b24(lbl_804ab60c+i*204)[counts]++;
        }
    }
}

void s9_count_pool_categories_80187768(int *counts)
{
    unsigned short i;
    for(i=0;i<lbl_804ab684;i++) {
        if(fn_80185b0c(lbl_804ab680+i*172)) {
            fn_80185b24(lbl_804ab680+i*172)[counts]++;
        }
    }
}

unsigned char s9_virtual_byte_8018915c(void *self)
{
    void *inner=FIELD(self,void *,116);
    return *FIELD(FIELD(inner,void *,0),S9ByteMethod,72)(inner);
}

void *s9_property_data_80189518(void *self)
{
    void *parent=FIELD(self,void *,168);
    void *owner=FIELD(parent,void *,48);
    S9PropertyHeader **slot=(S9PropertyHeader **)((char *)owner+64);
    S9PropertyHeader *h=*slot;
    int kind=h->kind;
    int count=h->count;
    void *result;
    if(kind!=1) goto slow;
    h->refs++;
    result=h->data;
    goto done;
slow:
    result=fn_801ef048(slot,count,12,2);
done:
    return result;
}

void *s9_property_data_80189704(void *self)
{
    void *parent=FIELD(self,void *,168);
    void *owner=FIELD(parent,void *,48);
    S9PropertyHeader **slot=(S9PropertyHeader **)((char *)owner+96);
    S9PropertyHeader *h=*slot;
    int kind=h->kind;
    int count=h->count;
    void *result;
    if(kind!=1) goto slow;
    h->refs++;
    result=h->data;
    goto done;
slow:
    result=fn_801ef048(slot,count,1,2);
done:
    return result;
}

void *s9_property_data_80189828(void *self)
{
    void *parent=FIELD(self,void *,168);
    void *owner=FIELD(parent,void *,48);
    S9PropertyHeader **slot=(S9PropertyHeader **)((char *)owner+100);
    S9PropertyHeader *h=*slot;
    int kind=h->kind;
    int count=h->count;
    void *result;
    if(kind!=1) goto slow;
    h->refs++;
    result=h->data;
    goto done;
slow:
    result=fn_801ef048(slot,count,1,2);
done:
    return result;
}

void *s9_property_data_80189884(void *self)
{
    void *parent=FIELD(self,void *,168);
    void *owner=FIELD(parent,void *,52);
    S9PropertyHeader **slot=(S9PropertyHeader **)((char *)owner+40);
    S9PropertyHeader *h=*slot;
    int kind=h->kind;
    int count=h->count;
    void *result;
    if(kind!=1) goto slow;
    h->refs++;
    result=h->data;
    goto done;
slow:
    result=fn_801ef048(slot,count,8,2);
done:
    return result;
}
