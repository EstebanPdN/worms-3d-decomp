/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d27e_lod_select_801a46bc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
slots_80363b18 = 0x80363b18;
SECTIONS {
  .text.w3d_d27e_lod_select_801a46bc 0x801a46bc : { *(.text.w3d_d27e_lod_select_801a46bc) }
  .rodata 0x803a9c20 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
