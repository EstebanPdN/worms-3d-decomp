/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d26a_emitters_setup_800370cc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_emitter_create_8025dffc = 0x8025dffc;
w3d_emitter_place_8025ee60 = 0x8025ee60;
w3d_emitter_setup_8025e128 = 0x8025e128;
w3d_heap_alloc_801fe1d8 = 0x801fe1d8;
SECTIONS {
  .text.w3d_d26a_emitters_setup_800370cc 0x800370cc : { *(.text.w3d_d26a_emitters_setup_800370cc) }
  .rodata 0x80373d40 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
