/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_ballistic_init_800d78ec)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_ballistic_base_destroy_800ea324 = 0x800ea324;
w3d_ballistic_base_init_800ea180 = 0x800ea180;
w3d_ballistic_vtable_8040fd88 = 0x8040fd88;
SECTIONS {
  .text.w3d_ballistic_init_800d78ec 0x800d78ec : { *(.text.w3d_ballistic_init_800d78ec) }
  .text.w3d_ballistic_destroy_800d797c 0x800d797c : { *(.text.w3d_ballistic_destroy_800d797c) }
  .rodata 0x803891e4 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
