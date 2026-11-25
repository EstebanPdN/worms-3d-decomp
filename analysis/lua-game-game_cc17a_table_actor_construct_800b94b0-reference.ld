/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cc17a_table_actor_construct_800b94b0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
base_8015fef0 = 0x8015fef0;
string_803426b8 = 0x803426b8;
table_8040f7d8 = 0x8040f7d8;
SECTIONS {
  .text.w3d_cc17a_table_actor_construct_800b94b0 0x800b94b0 : { *(.text.w3d_cc17a_table_actor_construct_800b94b0) }
  .sdata 0x804aad30 (NOLOAD) : {
    . = 0x0; global_804aad30 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
