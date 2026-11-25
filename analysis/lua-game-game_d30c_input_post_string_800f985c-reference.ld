/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d30c_input_post_string_800f985c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__vt_10PostRecord = 0x804104e0;
__vt_8PostBase = 0x80410500;
process_800f9db8 = 0x800f9db8;
string_default_803426b8 = 0x803426b8;
w3d_handle_storage_allocate = 0x80212fd4;
w3d_handle_storage_fallback = 0x803413d8;
w3d_handle_storage_release = 0x802134fc;
w3d_string_base_finish = 0x8020c5c4;
w3d_string_base_init = 0x8020c5c0;
w3d_string_header = 0x80341884;
w3d_string_release = 0x80341588;
w3d_string_release_header = 0x8020bb2c;
SECTIONS {
  .text.d30c_input_post_string_800f985c 0x800f985c : { *(.text.d30c_input_post_string_800f985c) }
  .sdata 0x804aaf48 (NOLOAD) : {
    . = 0x0; input_804aaf48 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
