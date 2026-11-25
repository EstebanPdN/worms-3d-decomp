/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s4_image_construct)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_ctor_8015fef0 = 0x8015fef0;
w3d_image_base_construct_802afb20 = 0x802afb20;
w3d_vtable_8041c120 = 0x8041c120;
w3d_vtable_8041c170 = 0x8041c170;
SECTIONS {
  .text.w3d_s4_image_construct 0x8028cde0 : { *(.text.w3d_s4_image_construct) }
  .text.w3d_s4_image_visibility 0x8028d34c : { *(.text.w3d_s4_image_visibility) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
