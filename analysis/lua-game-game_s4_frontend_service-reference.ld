/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s4_frontend_service_construct)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_ctor_801628b0 = 0x801628b0;
w3d_lookup_value_800fc330 = 0x800fc330;
w3d_service_destroy_801628ec = 0x801628ec;
w3d_vtable_8041c1f0 = 0x8041c1f0;
SECTIONS {
  .text.w3d_s4_frontend_service_construct 0x8028ef10 : { *(.text.w3d_s4_frontend_service_construct) }
  .text.w3d_s4_frontend_service_destroy 0x8028ef7c : { *(.text.w3d_s4_frontend_service_destroy) }
  .text.w3d_s4_frontend_named_value_differs 0x8028fa7c : { *(.text.w3d_s4_frontend_named_value_differs) }
  .sdata 0x804abbfc (NOLOAD) : {
    . = 0x0; w3d_frontend_instance_804abbfc = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
