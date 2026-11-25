/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_k8a_entry_tree_parse_800b0474)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
k4a_entry_construct_800afdd4 = 0x800afdd4;
strtok = 0x802efd7c;
w3d_entry_origin_parse_800b0530 = 0x800b0530;
w3d_heap_allocate = 0x802098d8;
w3d_string_assign = 0x8020bd38;
SECTIONS {
  .text.w3d_k8a_entry_tree_parse_800b0474 0x800b0474 : { *(.text.w3d_k8a_entry_tree_parse_800b0474) }
  .sdata 0x804aacb8 (NOLOAD) : {
    . = 0x0; w3d_delimiters_804aacb8 = .;
    . = 0x538c; w3d_heap_804b0044 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
