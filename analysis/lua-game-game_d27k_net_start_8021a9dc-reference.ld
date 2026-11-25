/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d27k_net_start_8021a9dc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
acquire_80162024 = 0x80162024;
active_8021ec2c = 0x8021ec2c;
alloc_801613f0 = 0x801613f0;
cast_803426b4 = 0x803426b4;
connect_8021adb8 = 0x8021adb8;
context_80165254 = 0x80165254;
fn_8021cd10 = 0x8021cd10;
get_8021ed14 = 0x8021ed14;
init_80125fdc = 0x80125fdc;
lookup_800fc1b0 = 0x800fc1b0;
msgid_8015f5a0 = 0x8015f5a0;
object_80240994 = 0x80240994;
pooladd_800c53a0 = 0x800c53a0;
refresh_8021ad34 = 0x8021ad34;
text_803b3b98 = 0x803b3b98;
text_803b3bac = 0x803b3bac;
text_803b3bc0 = 0x803b3bc0;
SECTIONS {
  .text.w3d_d27k_net_start_8021a9dc 0x8021a9dc : { *(.text.w3d_d27k_net_start_8021a9dc) }
  .sdata 0x804aaabc (NOLOAD) : {
    . = 0x0; global_804aaabc = .;
    . = 0x198; global_804aac54 = .;
    . = 0x48c; global_804aaf48 = .;
    . = 0x5c60; cache_804b071c = .;
    . = 0x5c98; cache_804b0754 = .;
    . = 0x5ca0; cache_804b075c = .;
    . = 0x5cb0; cache_804b076c = .;
    . = 0x5cb8; cache_804b0774 = .;
    . = 0x5cc8; cache_804b0784 = .;
    . = 0x6c98; global_804b1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
