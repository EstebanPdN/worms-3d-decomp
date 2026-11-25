/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s19_destroy_800222b8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
lbl_8040ddb8 = 0x8040ddb8;
w3d_actor_base_destroy = 0x80161050;
w3d_handle_storage_release = 0x802134fc;
SECTIONS {
  .text.s19_destroy_800222b8 0x800222b8 : { *(.text.s19_destroy_800222b8) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
