/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cx12b_sound_payload_deserialize_801df7f4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
allocate_801fe220 = 0x801fe220;
release_801fe240 = 0x801fe240;
SECTIONS {
  .text.w3d_cx12b_sound_payload_deserialize_801df7f4 0x801df7f4 : { *(.text.w3d_cx12b_sound_payload_deserialize_801df7f4) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
