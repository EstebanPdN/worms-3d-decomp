/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_k2b_light_construct_801cb590)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_light_base_init_801cb41c = 0x801cb41c;
w3d_vtable_80416208 = 0x80416208;
SECTIONS {
  .text.w3d_k2b_light_construct_801cb590 0x801cb590 : { *(.text.w3d_k2b_light_construct_801cb590) }
  .rodata 0x803add6c : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
