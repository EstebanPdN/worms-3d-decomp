/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d27d_worm_destroy_801421c8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
actor_destroy_80161050 = 0x80161050;
handle_destroy_80126230 = 0x80126230;
method_destroy_80118200 = 0x80118200;
optional_delete_8014127c = 0x8014127c;
storage_release_802134fc = 0x802134fc;
vtable_80410f00 = 0x80410f00;
SECTIONS {
  .text.d27d_worm_destroy_801421c8 0x801421c8 : { *(.text.d27d_worm_destroy_801421c8) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
