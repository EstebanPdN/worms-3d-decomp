// Archivos del juego: rutas del disco sin distinguir mayúsculas, sobre la copia local del usuario.
// Mods: <copia>/mods/*.worms (formato de assets.worms, ver platform/3ds/vfs_3ds.cpp) se miran antes que files/,
// en orden alfabético. Un archivo del mod sustituye al del disco o añade uno nuevo.
#include "../platform.h"
#include "../../core/native/parches_vfs.h"
#include <algorithm>
#include <stdint.h>
#include <vector>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <string>
#include <sys/stat.h>
#include <unordered_map>

namespace w3d {
namespace plat {

struct File { FILE *h; long size, base; const W3dTramo *t; int nt; };
}  // namespace plat
}  // namespace w3d
extern "C" int w3d_builtin_file(const char *path, const unsigned char **data, unsigned *size);
// Archivos que se sirven parcheados (core/native/parches_vfs.cpp: Spanish.xom de la v25, entero en memoria; el bundle
// del worm de la v26, por tramos; core/native/parches_vfs.h).
namespace w3d {
namespace plat {
static File *new_file(FILE *h, long size, long base) {
    File *f = (File *)malloc(sizeof(File));
    f->h = h; f->size = size; f->base = base; f->t = nullptr; f->nt = 0;
    return f;
}
// Forma 1: lee el archivo entero de h (desde base) y, si el parche cambia algo, lo sirve desde memoria y cierra h.
static File *patched(const char *game_path, FILE *h, long base, long size) {
    int k = w3d_parche_quiere(game_path);
    if (k == 0 || w3d_parche_es_tramos(k) || size <= 0) return nullptr;   // forma 1: parches 1, 4 y 5 (parches_vfs.cpp)
    const unsigned char *data; unsigned n;
    if (!w3d_parche_aplica(k, nullptr, 0, &data, &n)) {   // ya parcheado: sin volver a leerlo
        std::vector<unsigned char> raw((size_t)size);
        if (fseek(h, base, SEEK_SET) != 0 || fread(raw.data(), 1, (size_t)size, h) != (size_t)size) return nullptr;
        if (!w3d_parche_aplica(k, raw.data(), (unsigned)size, &data, &n)) return nullptr;
    }
    FILE *m = fmemopen((void *)data, n, "rb");
    if (!m) return nullptr;
    fclose(h);
    return new_file(m, (long)n, 0);
}
// Forma 2: el archivo como lista de tramos, cada uno del original (h desde base) o de memoria.
struct ReadCtx { FILE *h; long base; };
static int read_original(void *ctx, unsigned off, void *dst, unsigned n) {
    ReadCtx *c = (ReadCtx *)ctx;
    return fseek(c->h, c->base + (long)off, SEEK_SET) == 0 && fread(dst, 1, n, c->h) == n;
}
static File *by_segments(const char *game_path, FILE *h, long base, long size) {
    const int k = size > 0 ? w3d_parche_quiere(game_path) : 0;
    if (!w3d_parche_es_tramos(k)) return nullptr;
    ReadCtx c = {h, base};
    const W3dTramo *t; int n;
    if (!w3d_parche_tramos(k, read_original, &c, (unsigned)size, &t, &n)) return nullptr;
    long total = 0;
    for (int i = 0; i < n; i++) total += t[i].bytes;
    File *f = new_file(h, total, base);
    f->t = t; f->nt = n;
    return f;
}

static std::string g_files;
static std::unordered_map<std::string, std::string> g_cache;
struct ModEntry { uint64_t offset; uint32_t size; };
struct Mod { std::string path; std::unordered_map<std::string, ModEntry> files; };
static std::vector<Mod> g_mods;

static std::string lower(std::string s) {
    for (auto &c : s) { if (c >= 'A' && c <= 'Z') c += 32; if (c == '\\') c = '/'; }
    return s;
}

static void mount_mods(const std::string &dir) {
    g_mods.clear();
    DIR *d = opendir(dir.c_str());
    if (!d) return;
    std::vector<std::string> names;
    while (dirent *de = readdir(d)) {
        size_t n = strlen(de->d_name);
        if (de->d_name[0] != '.' && n > 6 && !strcasecmp(de->d_name + n - 6, ".worms")) names.push_back(de->d_name);
    }
    closedir(d);
    std::sort(names.begin(), names.end());
    for (const std::string &nm : names) {
        Mod m; m.path = dir + "/" + nm;
        FILE *h = fopen(m.path.c_str(), "rb");
        if (!h) continue;
        struct { char magic[8]; uint32_t version, count; uint64_t table; uint32_t table_bytes, names_bytes; } hdr;
        bool ok = fread(&hdr, sizeof hdr, 1, h) == 1 && !memcmp(hdr.magic, "WORMSPK1", 8) && hdr.version == 1;
        std::vector<char> table, names_blob;
        if (ok) {
            table.resize(hdr.table_bytes); names_blob.resize(hdr.names_bytes + 1);
            ok = fseek(h, (long)hdr.table, SEEK_SET) == 0 && fread(table.data(), 1, table.size(), h) == table.size() &&
                 fread(names_blob.data(), 1, hdr.names_bytes, h) == hdr.names_bytes;
        }
        fclose(h);
        if (!ok) { fprintf(stderr, "[vfs] mod no válido: %s\n", m.path.c_str()); continue; }
        for (uint32_t i = 0; i < hdr.count && (i + 1) * 24 <= table.size(); i++) {
            const char *e = table.data() + i * 24;
            uint32_t name; uint64_t off; uint32_t size;
            memcpy(&name, e + 4, 4); memcpy(&off, e + 8, 8); memcpy(&size, e + 16, 4);
            if (name < hdr.names_bytes) m.files[lower(names_blob.data() + name)] = ModEntry{off, size};
        }
        fprintf(stderr, "[vfs] mod %s: %zu archivos\n", m.path.c_str(), m.files.size());
        g_mods.push_back(std::move(m));
    }
}

void vfs_mount(const char *data_root) { g_files = std::string(data_root) + "/files"; g_cache.clear(); // W3D_MODS=<carpeta> cambia la carpeta de mods (la copia del juego puede ser de solo lectura).
    const char *mods = getenv("W3D_MODS");
    mount_mods(mods && *mods ? std::string(mods) : std::string(data_root) + "/mods"); }

static bool resolve(const char *game_path, std::string *out) {
    std::string key = lower(game_path);
    while (!key.empty() && key[0] == '/') key.erase(0, 1);
    auto it = g_cache.find(key);
    if (it != g_cache.end()) { *out = it->second; return true; }
    std::string cur = g_files; size_t pos = 0;
    while (pos < key.size()) {
        size_t e = key.find('/', pos);
        if (e == std::string::npos) e = key.size();
        std::string part = key.substr(pos, e - pos);
        pos = e + 1;
        DIR *d = opendir(cur.c_str());
        if (!d) return false;
        bool found = false;
        while (dirent *de = readdir(d)) {
            if (!strcasecmp(de->d_name, part.c_str())) { cur += "/"; cur += de->d_name; found = true; break; }
        }
        closedir(d);
        if (!found) return false;
    }
    g_cache[key] = cur; *out = cur;
    return true;
}

File *file_open(const char *game_path) {
    if (!g_mods.empty()) {
        std::string key = lower(game_path);
        while (!key.empty() && key[0] == '/') key.erase(0, 1);
        for (const Mod &m : g_mods) {
            auto it = m.files.find(key);
            if (it == m.files.end()) continue;
            FILE *h = fopen(m.path.c_str(), "rb");
            if (!h) return nullptr;
            if (File *p = by_segments(game_path, h, (long)it->second.offset, (long)it->second.size)) return p;
            if (File *p = patched(game_path, h, (long)it->second.offset, (long)it->second.size)) return p;
            return new_file(h, (long)it->second.size, (long)it->second.offset);
        }
    }
    std::string real;
    if (!resolve(game_path, &real)) {
        // Archivos incrustados en el ejecutable (core/native/hat_militar.cpp: Bundles/Bundle89.xom).
        const unsigned char *data; unsigned size;
        if (!w3d_builtin_file(game_path, &data, &size)) return nullptr;
        FILE *h = fmemopen((void *)data, size, "rb");
        if (!h) return nullptr;
        return new_file(h, (long)size, 0);
    }
    FILE *h = fopen(real.c_str(), "rb");
    if (!h) return nullptr;
    struct stat st;
    if (fstat(fileno(h), &st) != 0) { fclose(h); return nullptr; }
    if (File *p = by_segments(game_path, h, 0, (long)st.st_size)) return p;
    if (File *p = patched(game_path, h, 0, (long)st.st_size)) return p;
    return new_file(h, (long)st.st_size, 0);
}
long file_size(File *f) { return f->size; }
long file_read(File *f, void *dst, long offset, long bytes) {
    if (offset < 0 || offset >= f->size) return 0;
    if (offset + bytes > f->size) bytes = f->size - offset;
    if (f->t) {   // Por tramos: cada trozo del original o de memoria.
        long done = 0, start = 0;
        for (int i = 0; i < f->nt && done < bytes; i++) {
            const W3dTramo &s = f->t[i];
            long end = start + (long)s.bytes, pos = offset + done;
            if (pos < end) {
                long n = end - pos < bytes - done ? end - pos : bytes - done, rel = pos - start;
                if (s.mem) memcpy((char *)dst + done, s.mem + rel, (size_t)n);
                else if (fseek(f->h, f->base + (long)s.desde + rel, SEEK_SET) != 0 || fread((char *)dst + done, 1, (size_t)n, f->h) != (size_t)n) return -1;
                done += n;
            }
            start = end;
        }
        return done;
    }
    if (fseek(f->h, f->base + offset, SEEK_SET) != 0) return -1;
    return (long)fread(dst, 1, (size_t)bytes, f->h);
}
void file_close(File *f) { if (f) { fclose(f->h); free(f); } }

}  // namespace plat
}  // namespace w3d
