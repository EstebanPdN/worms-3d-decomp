/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s4_mouse_construct)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_base_destroy_8015ff2c = 0x8015ff2c;
w3d_ctor_8015fef0 = 0x8015fef0;
w3d_f32_803cf35c = 0x803cf35c;
w3d_vtable_8041bf00 = 0x8041bf00;
SECTIONS {
  .text.w3d_s4_mouse_construct 0x80284d74 : { *(.text.w3d_s4_mouse_construct) }
  .text.w3d_s4_mouse_destroy 0x80284de8 : { *(.text.w3d_s4_mouse_destroy) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
