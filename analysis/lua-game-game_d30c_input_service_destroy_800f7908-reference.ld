/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d30c_input_service_destroy_800f7908)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
base_destroy_801628ec = 0x801628ec;
table_80410480 = 0x80410480;
w3d_handle_storage_release = 0x802134fc;
w3d_string_base_finish = 0x8020c5c4;
w3d_string_release = 0x80341588;
SECTIONS {
  .text.d30c_input_service_destroy_800f7908 0x800f7908 : { *(.text.d30c_input_service_destroy_800f7908) }
  .sdata 0x804aaf48 (NOLOAD) : {
    . = 0x0; service_804aaf48 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
