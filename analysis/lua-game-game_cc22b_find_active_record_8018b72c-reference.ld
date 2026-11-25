/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cc22b_find_active_record_8018b72c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
SECTIONS {
  .text.w3d_cc22b_find_active_record_8018b72c 0x8018b72c : { *(.text.w3d_cc22b_find_active_record_8018b72c) }
  .sdata 0x804b18ac (NOLOAD) : {
    . = 0x0; cc22b_record_count_804b18ac = .;
    . = 0x4; cc22b_records_804b18b0 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
