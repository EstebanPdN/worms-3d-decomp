/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_h1_node_construct_8018bd30)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
s9_construct_shared_node_8017990c = 0x8017990c;
w3d_construct_802109dc = 0x802109dc;
w3d_string_default = 0x803426b8;
w3d_vtable_80412f50 = 0x80412f50;
SECTIONS {
  .text.w3d_h1_node_construct_8018bd30 0x8018bd30 : { *(.text.w3d_h1_node_construct_8018bd30) }
  .sdata 0x804ab6ac (NOLOAD) : {
    . = 0x0; w3d_sda_node_count_804ab6ac = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
