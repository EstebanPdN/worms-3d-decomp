/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(cc28a_planner_update_gates_80020b44)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cc28a_active_80020834 = 0x80020834;
cc28a_allocate_801613f0 = 0x801613f0;
cc28a_dispatch_8015fc38 = 0x8015fc38;
cc28a_id_8015f5a0 = 0x8015f5a0;
cc28a_int_80178c48 = 0x80178c48;
cc28a_property_803426b4 = 0x803426b4;
cc28a_registry_80007cc4 = 0x80007cc4;
cc28a_stop_800063d0 = 0x800063d0;
cc28a_team_80007b44 = 0x80007b44;
cc28a_timer_8006e71c = 0x8006e71c;
cc28a_type_8040db38 = 0x8040db38;
cc28a_update_80006444 = 0x80006444;
SECTIONS {
  .text.cc28a_planner_update_gates_80020b44 0x80020b44 : { *(.text.cc28a_planner_update_gates_80020b44) }
  .sdata 0x804aa568 (NOLOAD) : {
    . = 0x0; cc28a_state_804aa568 = .;
    . = 0x18; cc28a_mode_804aa580 = .;
    . = 0x23c; cc28a_flag_804aa7a4 = .;
    . = 0x240; cc28a_flag_804aa7a8 = .;
    . = 0x244; cc28a_flag_804aa7ac = .;
    . = 0x248; cc28a_flag_804aa7b0 = .;
    . = 0x24c; cc28a_flag_804aa7b4 = .;
    . = 0xe7c; cc28a_wait_804ab3e4 = .;
    . = 0x2438; cc28a_name_804ac9a0 = .;
    . = 0x71ec; cc28a_messages_804b1754 = .;
    . = 0x71f0; cc28a_queue_804b1758 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
