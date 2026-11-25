/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d26a_emitters_update_80036f88)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cos_802e86d4 = 0x802e86d4;
sin_802e88ac = 0x802e88ac;
w3d_emitter_setup_8025e128 = 0x8025e128;
w3d_extra_8029358c = 0x8029358c;
SECTIONS {
  .text.w3d_d26a_emitters_update_80036f88 0x80036f88 : { *(.text.w3d_d26a_emitters_update_80036f88) }
  .rodata 0x80373d10 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
