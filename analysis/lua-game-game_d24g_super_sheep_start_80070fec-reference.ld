/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d24g_super_sheep_start_80070fec)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
arena_alloc_801613f0 = 0x801613f0;
context_80165254 = 0x80165254;
empty_80341584 = 0x80341584;
events_800ed090 = 0x800ed090;
forward_800fdc80 = 0x800fdc80;
lookup_80164fc8 = 0x80164fc8;
message_id_8015f5a0 = 0x8015f5a0;
message_post_8016239c = 0x8016239c;
message_string_init_8010a8e0 = 0x8010a8e0;
multiply_801f606c = 0x801f606c;
play_800edd1c = 0x800edd1c;
read_resource_800fc1b0 = 0x800fc1b0;
rotation_801a3eb0 = 0x801a3eb0;
s_8037ca60 = 0x8037ca60;
s_8037ca78 = 0x8037ca78;
s_8037ca80 = 0x8037ca80;
sfx_8045e788 = 0x8045e788;
step_800ed784 = 0x800ed784;
string_assign_8020bd38 = 0x8020bd38;
subscribe_80162024 = 0x80162024;
team_801797b4 = 0x801797b4;
SECTIONS {
  .text.w3d_d24g_super_sheep_start_80070fec 0x80070fec : { *(.text.w3d_d24g_super_sheep_start_80070fec) }
  .rodata 0x8037ca94 : { *(.rodata) }
  .sdata 0x804aaae8 (NOLOAD) : {
    . = 0x0; g_804aaae8 = .;
    . = 0x4; g_804aaaec = .;
    . = 0x2ddc; msg_804ad8c4 = .;
    . = 0x2de4; msg_804ad8cc = .;
    . = 0x2dec; msg_804ad8d4 = .;
    . = 0x2df4; msg_804ad8dc = .;
    . = 0x2dfc; msg_804ad8e4 = .;
    . = 0x2e04; msg_804ad8ec = .;
    . = 0x2e0c; msg_804ad8f4 = .;
    . = 0x2e14; msg_804ad8fc = .;
    . = 0x2e1c; msg_804ad904 = .;
    . = 0x2e24; msg_804ad90c = .;
    . = 0x2e2c; msg_804ad914 = .;
    . = 0x2e34; msg_804ad91c = .;
    . = 0x2e44; msg_804ad92c = .;
    . = 0x6c6c; arena_804b1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
