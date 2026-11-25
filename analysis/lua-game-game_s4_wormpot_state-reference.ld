/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s4_wormpot_start)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_fn_802aa8a4 = 0x802aa8a4;
SECTIONS {
  .text.w3d_s4_wormpot_start 0x802aa33c : { *(.text.w3d_s4_wormpot_start) }
  .text.w3d_s4_wormpot_stop 0x802aa3a4 : { *(.text.w3d_s4_wormpot_stop) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
