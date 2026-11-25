// Inferred endpoint interface and observed offsets. Eight-byte output workspace is sufficient; original declaration and full sizeof remain unknown.
typedef unsigned int cc31b_u32;
struct Cc31bEndpoint_802cc8ec;
struct Cc31bEndpointTable_802cc8ec {
    void (*unused0)(); void (*unused1)(); void (*unused2)();
    void (*retain)(Cc31bEndpoint_802cc8ec*);
    void (*release)(Cc31bEndpoint_802cc8ec*);
    void (*unused5)();
    int (*write)(Cc31bEndpoint_802cc8ec*,const char*,cc31b_u32,int);
    void (*unused7)(); void (*unused8)(); void (*unused9)(); void (*unused10)();
    void (*flush)(Cc31bEndpoint_802cc8ec*);
    void (*unused12)();
    int (*accept)(Cc31bEndpoint_802cc8ec*,void*);
};
struct Cc31bEndpoint_802cc8ec { Cc31bEndpointTable_802cc8ec *table; };
struct Cc31bAccepted_802cc8ec { Cc31bEndpoint_802cc8ec *endpoint; cc31b_u32 opaque[1]; };
struct Cc31bReplyTable_802cc8ec { const char *text[10]; };
extern "C" {
extern int lbl_804abce4;
extern Cc31bEndpoint_802cc8ec *lbl_804b10b0;
extern char lbl_804b1964[4],lbl_804b1960[4];
extern Cc31bEndpoint_802cc8ec *lbl_80473764[];
extern Cc31bReplyTable_802cc8ec lbl_80403f54[];
extern const char *lbl_804abcc4;
cc31b_u32 fn_802ef9c0(const char*);
void fn_802cce78(Cc31bEndpoint_802cc8ec*);
}
static inline int cc31b_write_802cc8ec(Cc31bEndpoint_802cc8ec *p,const char *text) {
    Cc31bEndpointTable_802cc8ec *table=p->table;
    return table->write(p,text,fn_802ef9c0(text),0);
}
extern "C" void w3d_cc31b_accept_endpoint_802cc8ec() {
    Cc31bAccepted_802cc8ec accepted;
    if(lbl_804abce4 && lbl_804b10b0->table->accept(lbl_804b10b0,&accepted)>=0) {
        cc31b_u32 slot=0;
        cc31b_write_802cc8ec(accepted.endpoint,lbl_804b1964);
        cc31b_write_802cc8ec(accepted.endpoint,lbl_804b1960);
        if(lbl_80473764[0]) { do { ++slot; if(slot>15) break; } while(lbl_80473764[slot]); }
        if(slot==16) {
            cc31b_write_802cc8ec(accepted.endpoint,lbl_80403f54[0].text[1]);
            cc31b_write_802cc8ec(accepted.endpoint,lbl_804abcc4);
            cc31b_write_802cc8ec(accepted.endpoint,lbl_80403f54[0].text[9]);
            accepted.endpoint->table->flush(accepted.endpoint);
            accepted.endpoint->table->release(accepted.endpoint);
            accepted.endpoint=0;
        } else {
            Cc31bEndpoint_802cc8ec *replacement=accepted.endpoint;
            Cc31bEndpoint_802cc8ec **dest=(Cc31bEndpoint_802cc8ec**)((slot<<2)+(char*)lbl_80473764);
            if(replacement) replacement->table->retain(replacement);
            if(*dest) (*dest)->table->release(*dest);
            *dest=replacement;
            accepted.endpoint->table->release(accepted.endpoint);
            fn_802cce78(accepted.endpoint);
        }
    }
}
