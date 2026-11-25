/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cx7a_service_float_assign_800fc4c8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
assign_80178dfc = 0x80178dfc;
convert_80342a74 = 0x80342a74;
SECTIONS {
  .text.w3d_cx7a_service_float_assign_800fc4c8 0x800fc4c8 : { *(.text.w3d_cx7a_service_float_assign_800fc4c8) }
  .sdata 0x804b1788 (NOLOAD) : {
    . = 0x0; context_804b1788 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
