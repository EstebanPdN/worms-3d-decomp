/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_f1a_release_record_array_800b9b0c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
SECTIONS {
  .text.w3d_f1a_release_record_array_800b9b0c 0x800b9b0c : { *(.text.w3d_f1a_release_record_array_800b9b0c) }
  .sdata 0x804b183c (NOLOAD) : {
    . = 0x0; lbl_804b183c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
