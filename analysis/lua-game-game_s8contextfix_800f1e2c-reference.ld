/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s8_initialize_large_object_800f1e2c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8015FEF0 = 0x8015fef0;
lbl_804103A8 = 0x804103a8;
SECTIONS {
  .text.s8_initialize_large_object_800f1e2c 0x800f1e2c : { *(.text.s8_initialize_large_object_800f1e2c) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
