/* Original GameCube reference ABI. Names inferred; hardware and global state
 * remain external. No ARAM initialization, data ownership or native port claim. */
extern "C" {
extern unsigned int w3d_ref_aram_size;
unsigned int w3d_aram_base(void) { return 0x4000; }
unsigned int w3d_aram_size(void) { return w3d_ref_aram_size; }
}
