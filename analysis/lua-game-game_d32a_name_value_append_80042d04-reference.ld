/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d32a_name_value_append_80042d04)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
_S_oom_malloc__Q24_STLt14__malloc_alloc1i0Ui = 0x803413d8;
free = 0x802134fc;
malloc = 0x80212fd4;
memmove = 0x802eeef4;
w3d_string_base_finish = 0x8020c5c4;
w3d_string_base_init = 0x8020c5c0;
w3d_string_header = 0x80341884;
w3d_string_release = 0x80341588;
SECTIONS {
  .text.w3d_d32a_name_value_append_80042d04 0x80042d04 : { *(.text.w3d_d32a_name_value_append_80042d04) }
  .sdata 0x804aa978 (NOLOAD) : {
    . = 0x0; g_default_804aa978 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
