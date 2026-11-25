/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_k2b_emitter_construct_801cce74)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_emitter_base_init_801cb41c = 0x801cb41c;
w3d_vtable_80415fd8 = 0x80415fd8;
SECTIONS {
  .text.w3d_k2b_emitter_construct_801cce74 0x801cce74 : { *(.text.w3d_k2b_emitter_construct_801cce74) }
  .rodata 0x803ae4a4 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
