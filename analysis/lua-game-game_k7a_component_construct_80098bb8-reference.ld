/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_k7a_component_construct_80098bb8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_ctor_801628b0 = 0x801628b0;
w3d_vtable_8040f310 = 0x8040f310;
SECTIONS {
  .text.w3d_k7a_component_construct_80098bb8 0x80098bb8 : { *(.text.w3d_k7a_component_construct_80098bb8) }
  .sdata 0x804aabd4 (NOLOAD) : {
    . = 0x0; w3d_component_instance_804aabd4 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
