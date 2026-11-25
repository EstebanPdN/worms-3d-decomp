/* Inferred newlib fopen_r, original 0x802eb3c8. FILE fields observed:
 * flags +12 (u16), fd +14 (s16), cookie +28, callbacks +32..44,
 * reentrant owner +92. Unused fields remain opaque. Callback signatures
 * follow newlib's cookie-based I/O ABI; data and implementations stay external.
 */
struct Cx7cReent;
struct Cx7cFile {
    unsigned char unknown_00[12]; unsigned short flags; short fd;
    unsigned char unknown_10[12]; void *cookie;
    int (*read)(Cx7cReent *,void *,char *,int);
    int (*write)(Cx7cReent *,void *,const char *,int);
    long (*seek)(Cx7cReent *,void *,long,int);
    int (*close)(Cx7cReent *,void *);
    unsigned char unknown_30[44]; Cx7cReent *owner;
};
extern "C" {
int cx7c_parse_mode_802f34c8(Cx7cReent *,const char *,int *);
Cx7cFile *cx7c_file_allocate_802eb284(Cx7cReent *);
int cx7c_open_802f3328(Cx7cReent *,const char *,int,int);
int cx7c_read_802ec424(Cx7cReent *,void *,char *,int);
int cx7c_write_802ec488(Cx7cReent *,void *,const char *,int);
long cx7c_seek_802ec4f8(Cx7cReent *,void *,long,int);
int cx7c_close_802ec55c(Cx7cReent *,void *);
int cx7c_fseek_802eb704(Cx7cFile *,long,int);
}
extern "C" Cx7cFile *w3d_cx7c_fopen_reentrant_802eb3c8(Cx7cReent *owner,const char *path,const char *mode)
{
    int open_flags;
    int flags=cx7c_parse_mode_802f34c8(owner,mode,&open_flags);
    if (flags==0) return 0;
    Cx7cFile *file=cx7c_file_allocate_802eb284(owner);
    if (!file) return 0;
    file->flags&=2;
    int fd=cx7c_open_802f3328(file->owner,path,open_flags,0666);
    if (fd<0) {file->flags=0;return 0;}
    file->fd=fd;
    file->flags=flags;
    file->cookie=file;
    file->read=cx7c_read_802ec424;
    file->write=cx7c_write_802ec488;
    file->seek=cx7c_seek_802ec4f8;
    file->close=cx7c_close_802ec55c;
    if (flags&0x100) cx7c_fseek_802eb704(file,0,2);
    return file;
}
