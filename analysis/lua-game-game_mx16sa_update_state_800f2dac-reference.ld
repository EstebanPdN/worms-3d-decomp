/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(mx16sa_update_state_800f2dac)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
advance_pair_800f30f0 = 0x800f30f0;
finish_stage_800f46b8 = 0x800f46b8;
poll_stage_800f5148 = 0x800f5148;
refresh_stage_800f3ddc = 0x800f3ddc;
start_stage_800f35e4 = 0x800f35e4;
swap_handles_800f3028 = 0x800f3028;
SECTIONS {
  .text.mx16sa_update_state_800f2dac 0x800f2dac : { *(.text.mx16sa_update_state_800f2dac) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
