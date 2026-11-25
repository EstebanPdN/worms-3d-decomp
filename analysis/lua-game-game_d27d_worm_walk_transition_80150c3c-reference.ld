/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d27d_worm_walk_transition_80150c3c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
acos_802e79e0 = 0x802e79e0;
cos_802e86d4 = 0x802e86d4;
input_8014c260 = 0x8014c260;
invert_801f6c2c = 0x801f6c2c;
setAnim_801492ec = 0x801492ec;
sin_802e88ac = 0x802e88ac;
speed_80178ec4 = 0x80178ec4;
sqrt_802e82c0 = 0x802e82c0;
view_8014be44 = 0x8014be44;
SECTIONS {
  .text.d27d_worm_walk_transition_80150c3c 0x80150c3c : { *(.text.d27d_worm_walk_transition_80150c3c) }
  .rodata 0x803a1878 : { *(.rodata) }
  .sdata 0x804afdd8 (NOLOAD) : {
    . = 0x0; speedA_804afdd8 = .;
    . = 0x4; speedB_804afddc = .;
    . = 0x8; speedC_804afde0 = .;
    . = 0xc; speedD_804afde4 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
