/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s4_scheme_service_construct)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_ctor_801628b0 = 0x801628b0;
w3d_service_destroy_801628ec = 0x801628ec;
w3d_string_assign = 0x8020bd38;
w3d_string_base_finish = 0x8020c5c4;
w3d_string_default = 0x803426b8;
w3d_string_release = 0x80341588;
w3d_vtable_8041c270 = 0x8041c270;
SECTIONS {
  .text.w3d_s4_scheme_service_construct 0x80296a2c : { *(.text.w3d_s4_scheme_service_construct) }
  .text.w3d_s4_scheme_service_destroy 0x80296ae8 : { *(.text.w3d_s4_scheme_service_destroy) }
  .sdata 0x804abc0c (NOLOAD) : {
    . = 0x0; w3d_global_804abc0c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
