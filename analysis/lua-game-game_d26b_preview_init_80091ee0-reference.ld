/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d26b_preview_init_80091ee0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
strcmp_802ef234 = 0x802ef234;
w3d_array_ref_lock_801ef048 = 0x801ef048;
w3d_preview_build_800919d4 = 0x800919d4;
SECTIONS {
  .text.w3d_d26b_preview_init_80091ee0 0x80091ee0 : { *(.text.w3d_d26b_preview_init_80091ee0) }
  .rodata 0x8037e87c : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
