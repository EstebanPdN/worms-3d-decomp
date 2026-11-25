/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d24a_step_describe_8000a4e4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__6StringPCc = 0x8020bb54;
w3d_describe_8000756c = 0x8000756c;
w3d_string_80369bb4 = 0x80369bb4;
w3d_string_80369bbc = 0x80369bbc;
w3d_string_append_8020bf2c = 0x8020bf2c;
w3d_string_finish_8020c5c4 = 0x8020c5c4;
w3d_string_header_80341884 = 0x80341884;
w3d_string_init_8020c5c0 = 0x8020c5c0;
w3d_string_release_80341588 = 0x80341588;
SECTIONS {
  .text.w3d_d24a_step_describe_8000a4e4 0x8000a4e4 : { *(.text.w3d_d24a_step_describe_8000a4e4) }
  .sdata 0x804aa750 (NOLOAD) : {
    . = 0x0; w3d_ai_table_804aa750 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
