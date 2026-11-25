/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d42e_slot_table_acquire_8020777c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
free_802134fc = 0x802134fc;
malloc = 0x80212fd4;
memcpy = 0x802eee50;
w3d_s21_acquire_cleared_80207490 = 0x80207490;
SECTIONS {
  .text.w3d_d42e_slot_table_acquire_8020777c 0x8020777c : { *(.text.w3d_d42e_slot_table_acquire_8020777c) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
