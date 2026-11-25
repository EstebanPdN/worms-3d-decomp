/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d26k_log_allocation_80217dac)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
append_80217c6c = 0x80217c6c;
number_80217cd4 = 0x80217cd4;
strlen_802ef9c0 = 0x802ef9c0;
text_803b3814 = 0x803b3814;
text_803b381c = 0x803b381c;
text_803b3824 = 0x803b3824;
text_803b382c = 0x803b382c;
text_803b3834 = 0x803b3834;
write_802e3294 = 0x802e3294;
SECTIONS {
  .text.w3d_d26k_log_allocation_80217dac 0x80217dac : { *(.text.w3d_d26k_log_allocation_80217dac) }
  .sdata 0x804aba90 (NOLOAD) : {
    . = 0x0; global_804aba90 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
