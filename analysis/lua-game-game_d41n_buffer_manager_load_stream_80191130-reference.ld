/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d41n_buffer_manager_load_stream_80191130)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
_._4Body = 0x80197ce4;
__18W3dString_803426b8 = 0x803426b8;
__4Body = 0x80197c8c;
__builtin_vec_delete = 0x801fe240;
__builtin_vec_new = 0x801fe220;
fn_80197d78 = 0x80197d78;
fn_80197dd4 = 0x80197dd4;
fn_80197e08 = 0x80197e08;
fn_80197ed0 = 0x80197ed0;
fn_80197f0c = 0x80197f0c;
fn_8020bb2c = 0x8020bb2c;
fn_8020c048 = 0x8020c048;
fn_8020c0fc = 0x8020c0fc;
fn_8020c5c4 = 0x8020c5c4;
fn_80341588 = 0x80341588;
fn_8034f190 = 0x8034f190;
lbl_803a825c = 0x803a825c;
strcmp_802ef234 = 0x802ef234;
w3d_auto_801907d0 = 0x801907d0;
SECTIONS {
  .text.w3d_d41n_buffer_manager_load_stream_80191130 0x80191130 : { *(.text.w3d_d41n_buffer_manager_load_stream_80191130) }
  .sdata 0x804ab6d0 (NOLOAD) : {
    . = 0x0; lbl_804ab6d0 = .;
    . = 0x4; lbl_804ab6d4 = .;
    . = 0x8; lbl_804ab6d8 = .;
    . = 0xc; lbl_804ab6dc = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
