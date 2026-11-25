/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_mode_slots_release_8035a32c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_mode_apply_8020abe0 = 0x8020abe0;
w3d_mode_reset_8020ad18 = 0x8020ad18;
SECTIONS {
  .text.w3d_mode_slots_release_8035a32c 0x8035a32c : { *(.text.w3d_mode_slots_release_8035a32c) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
