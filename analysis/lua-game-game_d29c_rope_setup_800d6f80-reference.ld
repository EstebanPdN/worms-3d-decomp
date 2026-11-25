/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d29c_rope_setup_800d6f80)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
acos_802e7c30 = 0x802e7c30;
alloc_801613f0 = 0x801613f0;
find_800d7318 = 0x800d7318;
init_8010a8e0 = 0x8010a8e0;
k1_803890ac = 0x803890ac;
k2_803890b8 = 0x803890b8;
msg_id_8015f5a0 = 0x8015f5a0;
post_8016239c = 0x8016239c;
s1_803890c4 = 0x803890c4;
s2_803890d0 = 0x803890d0;
s3_803890dc = 0x803890dc;
s4_803890ec = 0x803890ec;
s5_803890f4 = 0x803890f4;
s6_8038910c = 0x8038910c;
s7_8038911c = 0x8038911c;
s8_80389128 = 0x80389128;
sqrt_802e82c0 = 0x802e82c0;
value_80178df0 = 0x80178df0;
SECTIONS {
  .text.d29c_rope_setup_800d6f80 0x800d6f80 : { *(.text.d29c_rope_setup_800d6f80) }
  .rodata 0x80389130 : { *(.rodata) }
  .sdata 0x804aeaa8 (NOLOAD) : {
    . = 0x0; idB_804aeaa8 = .;
    . = 0x8; idA_804aeab0 = .;
    . = 0x2cac; heap_804b1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
