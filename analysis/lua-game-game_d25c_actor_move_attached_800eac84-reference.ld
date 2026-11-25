/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d25c_actor_move_attached_800eac84)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
ctx_80165254 = 0x80165254;
desc_801797b4 = 0x801797b4;
empty_80341584 = 0x80341584;
set_801262c0 = 0x801262c0;
SECTIONS {
  .text.d25c_actor_move_attached_800eac84 0x800eac84 : { *(.text.d25c_actor_move_attached_800eac84) }
  .rodata 0x8038b3f8 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
