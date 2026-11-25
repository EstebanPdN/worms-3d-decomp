/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_remove_value_8008c3a8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801190d0 = 0x801190d0;
memcpy = 0x802eee50;
SECTIONS {
  .text.w3d_remove_value_8008c3a8 0x8008c3a8 : { *(.text.w3d_remove_value_8008c3a8) }
  .text.w3d_remove_value_8008c49c 0x8008c49c : { *(.text.w3d_remove_value_8008c49c) }
  .text.w3d_remove_value_8008c590 0x8008c590 : { *(.text.w3d_remove_value_8008c590) }
  .text.w3d_remove_value_8008c628 0x8008c628 : { *(.text.w3d_remove_value_8008c628) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
