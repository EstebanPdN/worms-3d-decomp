/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d24g_pause_trigger_8006bf7c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__6StringPCc = 0x8020bb54;
app_enter_80129878 = 0x80129878;
arena_alloc_801613f0 = 0x801613f0;
message_id_8015f5a0 = 0x8015f5a0;
message_post_8016239c = 0x8016239c;
message_string_8010a8e0 = 0x8010a8e0;
pause_800fde38 = 0x800fde38;
s_8037bd3c = 0x8037bd3c;
s_8037bed4 = 0x8037bed4;
s_8037bedc = 0x8037bedc;
s_8037beec = 0x8037beec;
select_slot_800a7e14 = 0x800a7e14;
string_assign_8020bd38 = 0x8020bd38;
string_finish_8020c5c4 = 0x8020c5c4;
string_release_80341588 = 0x80341588;
team_value_8021eb00 = 0x8021eb00;
timer_is_one_8006e71c = 0x8006e71c;
vt_8040db38 = 0x8040db38;
SECTIONS {
  .text.w3d_d24g_pause_trigger_8006bf7c 0x8006bf7c : { *(.text.w3d_d24g_pause_trigger_8006bf7c) }
  .sdata 0x804abac0 (NOLOAD) : {
    . = 0x0; network_804abac0 = .;
    . = 0x1c7c; msg_804ad73c = .;
    . = 0x1d34; msg_804ad7f4 = .;
    . = 0x1d3c; msg_804ad7fc = .;
    . = 0x1d4c; msg_804ad80c = .;
    . = 0x1d74; msg_804ad834 = .;
    . = 0x1d9c; msg_804ad85c = .;
    . = 0x5c94; arena_804b1754 = .;
    . = 0x5cc8; app_804b1788 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
