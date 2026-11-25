/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cx8b_registered_message_route_80215be4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8021573c = 0x8021573c;
ids_804640c0 = 0x804640c0;
SECTIONS {
  .text.w3d_cx8b_registered_message_route_80215be4 0x80215be4 : { *(.text.w3d_cx8b_registered_message_route_80215be4) }
  .sdata 0x804b06c4 (NOLOAD) : {
    . = 0x0; count_804b06c4 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
