/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cc17c_pending_flush_801fc8ac)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
allocate_80212fd4 = 0x80212fd4;
copy_802eee50 = 0x802eee50;
free_802134fc = 0x802134fc;
lbl_8045e890 = 0x8045e890;
SECTIONS {
  .text.w3d_cc17c_pending_flush_801fc8ac 0x801fc8ac : { *(.text.w3d_cc17c_pending_flush_801fc8ac) }
  .sdata 0x804b05d8 (NOLOAD) : {
    . = 0x0; lbl_804b05d8 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
