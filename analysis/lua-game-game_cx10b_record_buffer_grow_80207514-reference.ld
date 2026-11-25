/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cx10b_record_buffer_grow_80207514)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
allocate_802098d8 = 0x802098d8;
clear_802eefe0 = 0x802eefe0;
copy_802eee50 = 0x802eee50;
release_80209920 = 0x80209920;
SECTIONS {
  .text.w3d_cx10b_record_buffer_grow_80207514 0x80207514 : { *(.text.w3d_cx10b_record_buffer_grow_80207514) }
  .sdata 0x804b0644 (NOLOAD) : {
    . = 0x0; heap_804b0644 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
