/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d33c_earthquake_nuke_effect_800d2924)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
alloc_801613f0 = 0x801613f0;
cached_8015f5a0 = 0x8015f5a0;
get_float_800fc270 = 0x800fc270;
get_int_800fc1f0 = 0x800fc1f0;
get_int_800fc230 = 0x800fc230;
init_800a82f0 = 0x800a82f0;
post_8016239c = 0x8016239c;
quake_800e5ca4 = 0x800e5ca4;
query_800fc6dc = 0x800fc6dc;
set_float_800fc4c8 = 0x800fc4c8;
set_int_800fc3b0 = 0x800fc3b0;
set_int_800fc43c = 0x800fc43c;
sqrt_802e82c0 = 0x802e82c0;
vt_8040db38 = 0x8040db38;
zero_8045e788 = 0x8045e788;
SECTIONS {
  .text.d33c_earthquake_nuke_effect_800d2924 0x800d2924 : { *(.text.d33c_earthquake_nuke_effect_800d2924) }
  .rodata 0x80388b64 : { *(.rodata) }
  .sdata 0x804aa8c8 (NOLOAD) : {
    . = 0x0; game_804aa8c8 = .;
    . = 0x40f4; id_804ae9bc = .;
    . = 0x40fc; id_804ae9c4 = .;
    . = 0x4114; id_804ae9dc = .;
    . = 0x6e8c; arena_804b1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
