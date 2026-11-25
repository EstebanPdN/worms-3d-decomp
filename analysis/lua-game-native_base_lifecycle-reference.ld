/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_state_release_reference)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_original_8017eaa0 = 0x8017eaa0;
w3d_original_8017f198_for_base = 0x8017f198;
w3d_original_801fe1f8_for_base = 0x801fe1f8;
w3d_original_8020c5c4 = 0x8020c5c4;
w3d_original_80210990 = 0x80210990;
w3d_original_80341588 = 0x80341588;
w3d_ref_base_root_table = 0x80413270;
w3d_ref_base_table = 0x80413210;
SECTIONS {
  .text.w3d_state_release_reference 0x8017eb50 : { *(.text.w3d_state_release_reference) }
  .text.w3d_base_destroy 0x80190384 : { *(.text.w3d_base_destroy) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
