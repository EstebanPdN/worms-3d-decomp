// Reconstructed from original instructions at 0x8021907c. GC32 ABI.
struct Sol29bReadHandle { unsigned char observed_prefix[24]; int handle; };
extern "C" int sol29b_read_802e4cfc(int, void *, int);
extern "C" int sol29b_read_checked_8021907c(Sol29bReadHandle *self, void *destination, int requested, int *actual) {
 int count = sol29b_read_802e4cfc(self->handle, destination, requested);
 if (actual) *actual = count;
 int result = (int)0x80004005;
 if (count == requested) result = 0;
 return result;
}
