/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(k4a_entry_construct_800afdd4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_origin_8045e788 = 0x8045e788;
w3d_str_80382314 = 0x80382314;
w3d_string_assign = 0x8020bd38;
w3d_string_default = 0x803426b8;
SECTIONS {
  .text.k4a_entry_construct_800afdd4 0x800afdd4 : { *(.text.k4a_entry_construct_800afdd4) }
  .sdata 0x804aacac (NOLOAD) : {
    . = 0x0; w3d_count_804aacac = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
