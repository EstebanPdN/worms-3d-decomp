/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d30e_split_names_801d33b0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
_S_oom_malloc__Q24_STLt14__malloc_alloc1i0Ui = 0x803413d8;
__6StringPCc = 0x8020bb54;
__as__6StringPCc = 0x8020bd38;
free = 0x802134fc;
malloc = 0x80212fd4;
memcpy = 0x802eee50;
strchr = 0x802ef198;
w3d_string_base_finish = 0x8020c5c4;
w3d_string_base_init = 0x8020c5c0;
w3d_string_header = 0x80341884;
w3d_string_release = 0x80341588;
SECTIONS {
  .text.w3d_d30e_split_names_801d33b0 0x801d33b0 : { *(.text.w3d_d30e_split_names_801d33b0) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
