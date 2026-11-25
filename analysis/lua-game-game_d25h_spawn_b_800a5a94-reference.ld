/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d25h_spawn_800a5a94)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
_._19Descriptor_80178474 = 0x80178474;
__6String = 0x803426b8;
__6StringPCc = 0x8020bb54;
fn_800683fc = 0x800683fc;
fn_800fc710 = 0x800fc710;
fn_8015f5a0 = 0x8015f5a0;
fn_801613f0 = 0x801613f0;
fn_8016239c = 0x8016239c;
fn_80178ec4 = 0x80178ec4;
fn_8020c510 = 0x8020c510;
fn_80342fa4 = 0x80342fa4;
lbl_80381238 = 0x80381238;
lbl_80381240 = 0x80381240;
lbl_803f4bf8 = 0x803f4bf8;
w3d_string_finish_8020c5c4 = 0x8020c5c4;
w3d_string_free_8020bb2c = 0x8020bb2c;
w3d_string_release_80341588 = 0x80341588;
SECTIONS {
  .text.w3d_d25h_spawn_800a5a94 0x800a5a94 : { *(.text.w3d_d25h_spawn_800a5a94) }
  .rodata 0x80381248 : { *(.rodata) }
  .sdata 0x804ae278 (NOLOAD) : {
    . = 0x0; lbl_804ae278 = .;
    . = 0x34dc; lbl_804b1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
