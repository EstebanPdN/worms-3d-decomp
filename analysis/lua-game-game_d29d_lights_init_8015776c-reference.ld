/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d29d_lights_init_8015776c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
a_804540f4 = 0x804540f4;
b_80454100 = 0x80454100;
c_8045410c = 0x8045410c;
create_8020b680 = 0x8020b680;
desc_80414a90 = 0x80414a90;
fmtA_803a2c04 = 0x803a2c04;
fmtB_803a2c14 = 0x803a2c14;
sprintf_803442b4 = 0x803442b4;
sqrt_802e82c0 = 0x802e82c0;
SECTIONS {
  .text.d29d_lights_init_8015776c 0x8015776c : { *(.text.d29d_lights_init_8015776c) }
  .rodata 0x803a2c24 : { *(.rodata) }
  .sdata 0x804ab3b0 (NOLOAD) : {
    . = 0x0; flag_804ab3b0 = .;
    . = 0x4a60; guardA_804afe10 = .;
    . = 0x4a64; guardB_804afe14 = .;
    . = 0x4a68; guardC_804afe18 = .;
    . = 0x63d8; world_804b1788 = .;
    . = 0x643c; engine_804b17ec = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
