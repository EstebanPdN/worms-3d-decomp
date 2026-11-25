// GWMP8P rev0 0x8021d5c4. Checksums up to n bytes of a file: opens it, reads
// through an 8 KB temporary buffer and updates a CRC with each chunk until a
// short read, then returns the inverted value (0 when n is 0 or the open
// fails). Names are inferred from use.
struct File {
 char u[24];
 File();
 ~File();
 int Open(const char *, int);
 void * Read(void *, unsigned, unsigned *);
 int Close();
};
extern "C" void *fn_801fe0b8(unsigned);
extern "C" void fn_801fe160(void *);
extern "C" unsigned fn_8021d7ec(unsigned, void *, unsigned);
extern "C" unsigned w3d_d30k_file_checksum_8021d5c4(const char *path, unsigned n) {
 if (!n) return 0;
 File f;
 if (f.Open(path, 1) < 0) return 0;
 void *buf = fn_801fe0b8(8192);
 unsigned got = 0;
 if (n < 8192) f.Read(buf, n, &got);
 else f.Read(buf, 8192, &got);
 unsigned crc = fn_8021d7ec(-1, buf, got);
 unsigned v = got;
 if (v != 8192) goto D;
 L:
 n -= v;
 if (n < 8192) f.Read(buf, n, &got);
 else f.Read(buf, 8192, &got);
 crc = fn_8021d7ec(crc, buf, got);
 v = got;
 if (v == 8192) goto L;
 D:
 crc = ~crc;
 f.Close();
 fn_801fe160(buf);
 return crc;
}
