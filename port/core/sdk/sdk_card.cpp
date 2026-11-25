// Tarjeta de memoria sobre archivos locales: una carpeta con un archivo por partida.
// El contenido queda en el orden del anfitrión: estas partidas no son intercambiables con una GameCube.
#include "w3d_ptr.h"
#include <dirent.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <sys/stat.h>
#include <vector>

using namespace w3d;
typedef w3d_u32 GA;

namespace {
enum { READY = 0, NOCARD = -3, NOFILE = -4, EXIST = -7, NOENT = -8, INSSPACE = -9 };
const int kSector = 8192, kBlocks = 2043 - 5, kMaxFiles = 127;
struct FileInfo { int32_t chan, fileNo, offset, length; uint16_t iBlock, pad; };
struct Stat {
    char name[32]; uint32_t length, time; char game[4], company[2]; uint8_t banner_format, pad;
    uint32_t icon_addr; uint16_t icon_format, icon_speed; uint32_t comment_addr;
    uint32_t offset_banner, offset_banner_tlut, offset_icon[8], offset_icon_tlut, offset_data;
};
static_assert(sizeof(Stat) == 108, "disposición de CARDStat");

#if defined(__3DS__)
}  // namespace
extern "C" const char *w3d_sd_root(void);
namespace {
#endif
std::string dir_path() {
#if defined(__3DS__)
    std::string c = std::string(w3d_sd_root()) + "/card";
    mkdir(c.c_str(), 0755);
    return c;
#endif
    const char *home = getenv("HOME");
    std::string d = std::string(home ? home : "/tmp") + "/Library";
    mkdir(d.c_str(), 0755);
    d += "/Application Support";
    mkdir(d.c_str(), 0755);
    d += "/Worms3D";
    mkdir(d.c_str(), 0755);
    d += "/card";
    mkdir(d.c_str(), 0755);
    return d;
}
struct Entry { std::string name; Stat stat; };
std::vector<Entry> g_files;
bool g_loaded;

std::string path_of(const std::string &name) { return dir_path() + "/" + name; }
void save_meta(const Entry &e) {
    FILE *f = fopen((path_of(e.name) + ".meta").c_str(), "wb");
    if (f) { fwrite(&e.stat, sizeof e.stat, 1, f); fclose(f); }
}
void load_all() {
    if (g_loaded) return;
    g_loaded = true;
    std::string d = dir_path();
    DIR *h = opendir(d.c_str());
    if (!h) return;
    while (dirent *de = readdir(h)) {
        std::string n = de->d_name;
        if (n == "." || n == ".." || n.size() > 5 && n.substr(n.size() - 5) == ".meta") continue;
        Entry e;
        e.name = n;
        memset(&e.stat, 0, sizeof e.stat);
        FILE *m = fopen((path_of(n) + ".meta").c_str(), "rb");
        if (m) { fread(&e.stat, sizeof e.stat, 1, m); fclose(m); }
        strncpy(e.stat.name, n.c_str(), 31);
        struct stat st;
        if (!stat(path_of(n).c_str(), &st)) e.stat.length = (uint32_t)st.st_size;
        g_files.push_back(e);
    }
    closedir(h);
}
int find(const char *name) {
    for (size_t i = 0; i < g_files.size(); i++) if (g_files[i].name == name) return (int)i;
    return -1;
}
}  // namespace

extern "C" {
void A80314794(void) {}                                                       // CARDInit
int A80316270(int chan) { return chan == 0 ? 1 : 0; }                         // CARDProbe
int A803162a8(int chan, GA mem, GA sector) {                                  // CARDProbeEx
    if (chan != 0) return NOCARD;
    if (mem) *(int *)g2h(mem) = 16;     // 16 Mbit, como la tarjeta de 251 bloques.
    if (sector) *(int *)g2h(sector) = kSector;
    return READY;
}
int A80316b0c(int chan, GA, GA) { load_all(); return chan == 0 ? READY : NOCARD; }  // CARDMount
int A80316bf0(int) { return READY; }                                          // CARDUnmount
int A80316150(int chan) { return chan == 0 ? READY : NOCARD; }                // CARDCheck
int A80317438(int) { return READY; }                                          // CARDFormat
int A8031499c(int chan, GA bytes, GA files) {                                 // CARDFreeBlocks
    if (chan != 0) return NOCARD;
    load_all();
    long used = 0;
    for (auto &e : g_files) used += (e.stat.length + kSector - 1) / kSector;
    if (bytes) *(int *)g2h(bytes) = (int)((kBlocks - used) * kSector);
    if (files) *(int *)g2h(files) = kMaxFiles - (int)g_files.size();
    return READY;
}
int A803177b0(int chan, GA name, GA gfi) {                                    // CARDOpen
    load_all();
    if (chan != 0) return NOCARD;
    int i = find((const char *)g2h(name));
    if (i < 0) return NOFILE;
    FileInfo *fi = (FileInfo *)g2h(gfi);
    fi->chan = chan; fi->fileNo = i; fi->offset = 0; fi->length = (int)g_files[i].stat.length; fi->iBlock = 0;
    return READY;
}
int A803178cc(GA) { return READY; }                                           // CARDClose
int A80317c78(int chan, GA gname, unsigned size, GA gfi) {                    // CARDCreate
    load_all();
    if (chan != 0) return NOCARD;
    const char *name = (const char *)g2h(gname);
    if (find(name) >= 0) return EXIST;
    Entry e;
    e.name = name;
    memset(&e.stat, 0, sizeof e.stat);
    strncpy(e.stat.name, name, 31);
    e.stat.length = size;
    std::vector<uint8_t> zero(size);
    FILE *f = fopen(path_of(name).c_str(), "wb");
    if (!f) return INSSPACE;
    fwrite(zero.data(), 1, size, f);
    fclose(f);
    save_meta(e);
    g_files.push_back(e);
    FileInfo *fi = (FileInfo *)g2h(gfi);
    fi->chan = chan; fi->fileNo = (int)g_files.size() - 1; fi->offset = 0; fi->length = (int)size; fi->iBlock = 0;
    return READY;
}
int A803180ec(GA gfi, GA buf, int len, int off) {                             // CARDRead
    FileInfo *fi = (FileInfo *)g2h(gfi);
    if (fi->fileNo < 0 || (size_t)fi->fileNo >= g_files.size()) return NOFILE;
    FILE *f = fopen(path_of(g_files[fi->fileNo].name).c_str(), "rb");
    if (!f) return NOFILE;
    fseek(f, off, SEEK_SET);
    fread(g2h(buf), 1, (size_t)len, f);
    fclose(f);
    return READY;
}
int A80318468(GA gfi, GA buf, int len, int off) {                             // CARDWrite
    FileInfo *fi = (FileInfo *)g2h(gfi);
    if (fi->fileNo < 0 || (size_t)fi->fileNo >= g_files.size()) return NOFILE;
    FILE *f = fopen(path_of(g_files[fi->fileNo].name).c_str(), "r+b");
    if (!f) return NOFILE;
    fseek(f, off, SEEK_SET);
    fwrite(g2h(buf), 1, (size_t)len, f);
    fclose(f);
    return READY;
}
int A80318680(int, int fileNo) {                                              // CARDFastDelete
    if (fileNo < 0 || (size_t)fileNo >= g_files.size()) return NOFILE;
    remove(path_of(g_files[fileNo].name).c_str());
    remove((path_of(g_files[fileNo].name) + ".meta").c_str());
    g_files.erase(g_files.begin() + fileNo);
    return READY;
}
int A803188c0(int, int fileNo, GA st) {                                       // CARDGetStatus
    load_all();
    if (fileNo < 0 || (size_t)fileNo >= g_files.size()) return NOFILE;
    memcpy(g2h(st), &g_files[fileNo].stat, sizeof(Stat));
    return READY;
}
int A80318b48(int, int fileNo, GA st) {                                       // CARDSetStatus
    if (fileNo < 0 || (size_t)fileNo >= g_files.size()) return NOFILE;
    uint32_t length = g_files[fileNo].stat.length;
    memcpy(&g_files[fileNo].stat, g2h(st), sizeof(Stat));
    g_files[fileNo].stat.length = length;
    save_meta(g_files[fileNo]);
    return READY;
}
int A80318d8c(int, GA gold, GA gnew) {                                        // CARDRename
    int i = find((const char *)g2h(gold));
    if (i < 0) return NOFILE;
    std::string neu = (const char *)g2h(gnew);
    rename(path_of(g_files[i].name).c_str(), path_of(neu).c_str());
    rename((path_of(g_files[i].name) + ".meta").c_str(), (path_of(neu) + ".meta").c_str());
    g_files[i].name = neu;
    strncpy(g_files[i].stat.name, neu.c_str(), 31);
    save_meta(g_files[i]);
    return READY;
}
}
