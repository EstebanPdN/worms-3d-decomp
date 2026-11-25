/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_h1_actor_construct_80124edc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_actor_base_initialize = 0x80161014;
w3d_actor_handle_member_initialize = 0x80126184;
w3d_vtable_80410bd8 = 0x80410bd8;
SECTIONS {
  .text.w3d_h1_actor_construct_80124edc 0x80124edc : { *(.text.w3d_h1_actor_construct_80124edc) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
