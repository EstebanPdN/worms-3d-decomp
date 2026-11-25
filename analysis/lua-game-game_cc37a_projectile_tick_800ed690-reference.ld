/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(cc37a_projectile_tick_800ed690)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cc37a_config_801797b4 = 0x801797b4;
cc37a_move_800ec6a8 = 0x800ec6a8;
cc37a_paused_8006e71c = 0x8006e71c;
cc37a_step_800ed784 = 0x800ed784;
cc37a_stop_800ecb20 = 0x800ecb20;
cc37a_touch_80341584 = 0x80341584;
cc37a_zero_8038b618 = 0x8038b618;
SECTIONS {
  .text.cc37a_projectile_tick_800ed690 0x800ed690 : { *(.text.cc37a_projectile_tick_800ed690) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
