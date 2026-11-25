/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_format_into_80347a10)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
vsprintf = 0x802ed5e0;
SECTIONS {
  .text.w3d_format_into_80347a10 0x80347a10 : { *(.text.w3d_format_into_80347a10) }
  .text.w3d_format_into_8034cb64 0x8034cb64 : { *(.text.w3d_format_into_8034cb64) }
  .text.w3d_format_into_80351df8 0x80351df8 : { *(.text.w3d_format_into_80351df8) }
  .text.w3d_format_into_80355a44 0x80355a44 : { *(.text.w3d_format_into_80355a44) }
  .text.w3d_format_into_8035cb74 0x8035cb74 : { *(.text.w3d_format_into_8035cb74) }
  .text.w3d_format_into_8035eb0c 0x8035eb0c : { *(.text.w3d_format_into_8035eb0c) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
