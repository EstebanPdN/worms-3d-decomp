/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(cc43a_release_node_801799d4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cc43a_base_destroy_801858fc = 0x801858fc;
cc43a_member_destroy_801f2758 = 0x801f2758;
cc43a_member_destroy_80210abc = 0x80210abc;
cc43a_vtable_804126d0 = 0x804126d0;
SECTIONS {
  .text.cc43a_release_node_801799d4 0x801799d4 : { *(.text.cc43a_release_node_801799d4) }
  .sdata 0x804ab5d8 (NOLOAD) : {
    . = 0x0; cc43a_count_804ab5d8 = .;
    . = 0x4b88; cc43a_shared_804b0160 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
