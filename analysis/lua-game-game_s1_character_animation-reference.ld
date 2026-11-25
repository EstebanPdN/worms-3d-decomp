/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_fn_8006947c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_fn_80069630 = 0x80069630;
w3d_mesh_instance_is_playing = 0x80181ccc;
SECTIONS {
  .text.w3d_fn_8006947c 0x8006947c : { *(.text.w3d_fn_8006947c) }
  .text.w3d_fn_80069590 0x80069590 : { *(.text.w3d_fn_80069590) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
