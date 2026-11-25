struct s8_Adjustment { char pad0[64]; char *base; char pad68[18]; short offset; };
extern "C" char *s8_adjust_base_800f6c54(void *unused,const s8_Adjustment *p) { char *base=p->base; short offset=p->offset; return (char *)(offset+(int)base); }
