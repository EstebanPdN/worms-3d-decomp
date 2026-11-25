/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d26e_voice_volume_801e68d4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
sqrt_802e82c0 = 0x802e82c0;
w3d_sound_id_801e25d4 = 0x801e25d4;
SECTIONS {
  .text.w3d_d26e_voice_volume_801e68d4 0x801e68d4 : { *(.text.w3d_d26e_voice_volume_801e68d4) }
  .rodata 0x803b07f8 : { *(.rodata) }
  .sdata 0x804ab80c (NOLOAD) : {
    . = 0x0; lbl_804ab80c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
