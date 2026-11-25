/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(cc27a_planner_action_tick_80022850)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cc27a_activate_80022704 = 0x80022704;
cc27a_copy_802eee50 = 0x802eee50;
cc27a_reset_80022634 = 0x80022634;
cc27a_team_80020834 = 0x80020834;
cc27a_timer_8006e71c = 0x8006e71c;
SECTIONS {
  .text.cc27a_planner_action_tick_80022850 0x80022850 : { *(.text.cc27a_planner_action_tick_80022850) }
  .sdata 0x804b1760 (NOLOAD) : {
    . = 0x0; cc27a_owner_804b1760 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
