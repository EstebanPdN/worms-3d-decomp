/* Inferred newlib environment lookup at 0x802eda34. Takes reentrancy
 * context, a name optionally terminated by '=', and a slot out-parameter.
 * The original varargs lock ABI and its null-environ early return remain.
 */
struct Cx7cEnvReent;
extern "C" {
extern char **cx7c_environ_804ac5ac;
void cx7c_env_lock_802f3564(Cx7cEnvReent *,...);
void cx7c_env_unlock_802f3568(Cx7cEnvReent *,...);
int cx7c_strncmp_802efb1c(const char *,const char *,unsigned int);
}
extern "C" char *w3d_cx7c_env_lookup_802eda34(Cx7cEnvReent *owner,const char *name,int *slot)
{
    cx7c_env_lock_802f3564(owner);
    if (!cx7c_environ_804ac5ac) return 0;
    char *end=(char *)name;
    unsigned int length=0;
    while (*end && *end!='=') {++end;++length;}
    for (char **entry=cx7c_environ_804ac5ac;*entry;++entry) {
        if (cx7c_strncmp_802efb1c(*entry,name,length)==0 && *(end=*entry+length)=='=') {
            *slot=entry-cx7c_environ_804ac5ac;
            cx7c_env_unlock_802f3568(owner);
            return end+1;
        }
    }
    cx7c_env_unlock_802f3568(owner);
    return 0;
}
