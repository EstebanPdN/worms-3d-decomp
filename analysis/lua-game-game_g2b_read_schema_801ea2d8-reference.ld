/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(g2b_read_schema_801ea2d8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801eb0fc = 0x801eb0fc;
key_803b0a24 = 0x803b0a24;
key_803b0a28 = 0x803b0a28;
key_803b0a38 = 0x803b0a38;
key_803b0a44 = 0x803b0a44;
sentinel_80365788 = 0x80365788;
SECTIONS {
  .text.g2b_read_schema_801ea2d8 0x801ea2d8 : { *(.text.g2b_read_schema_801ea2d8) }
  .sdata 0x804ab89c (NOLOAD) : {
    . = 0x0; tag_804ab89c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
