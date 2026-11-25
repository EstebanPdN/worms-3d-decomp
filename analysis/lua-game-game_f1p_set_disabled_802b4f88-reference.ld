/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_set_disabled_802b4f88)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_80178c54 = 0x80178c54;
fn_80178d28 = 0x80178d28;
fn_803426b4 = 0x803426b4;
fn_80342a78 = 0x80342a78;
SECTIONS {
  .text.w3d_set_disabled_802b4f88 0x802b4f88 : { *(.text.w3d_set_disabled_802b4f88) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
