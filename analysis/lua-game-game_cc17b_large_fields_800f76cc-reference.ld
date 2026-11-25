/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cc17b_large_fields_800f76cc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801628b0 = 0x801628b0;
vtable_80410480 = 0x80410480;
SECTIONS {
  .text.w3d_cc17b_large_fields_800f76cc 0x800f76cc : { *(.text.w3d_cc17b_large_fields_800f76cc) }
  .sdata 0x804aaf48 (NOLOAD) : {
    . = 0x0; owner_804aaf48 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
