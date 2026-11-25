/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s4_controller_construct)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_ctor_801628b0 = 0x801628b0;
w3d_service_destroy_801628ec = 0x801628ec;
w3d_vtable_8041bfd0 = 0x8041bfd0;
SECTIONS {
  .text.w3d_s4_controller_construct 0x802873ac : { *(.text.w3d_s4_controller_construct) }
  .text.w3d_s4_controller_destroy 0x8028740c : { *(.text.w3d_s4_controller_destroy) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
