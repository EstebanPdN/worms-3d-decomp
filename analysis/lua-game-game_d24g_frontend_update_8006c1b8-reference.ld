/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d24g_frontend_update_8006c1b8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
arena_alloc_801613f0 = 0x801613f0;
callback_80069be0 = 0x80069be0;
context_80165254 = 0x80165254;
default_name_80127da4 = 0x80127da4;
fade_out_80126ac0 = 0x80126ac0;
finish_801ea57c = 0x801ea57c;
instance_80343994 = 0x80343994;
language_80127b48 = 0x80127b48;
message_id_8015f5a0 = 0x8015f5a0;
message_post_8016239c = 0x8016239c;
message_string_8010a8e0 = 0x8010a8e0;
names_clear_800c4604 = 0x800c4604;
read_800fc2b0 = 0x800fc2b0;
s_8037bf38 = 0x8037bf38;
s_8037bf44 = 0x8037bf44;
s_8037bf50 = 0x8037bf50;
select_slot_800a7e14 = 0x800a7e14;
set_byte_8015aee8 = 0x8015aee8;
set_callback_801fdbb4 = 0x801fdbb4;
set_mode_8006ab48 = 0x8006ab48;
step_8006f0dc = 0x8006f0dc;
strcmp = 0x802ef234;
vt_8040db38 = 0x8040db38;
SECTIONS {
  .text.w3d_d24g_frontend_update_8006c1b8 0x8006c1b8 : { *(.text.w3d_d24g_frontend_update_8006c1b8) }
  .sdata 0x804abb48 (NOLOAD) : {
    . = 0x0; g_804abb48 = .;
    . = 0x14; g_804abb5c = .;
    . = 0x1be4; msg_804ad72c = .;
    . = 0x1d24; msg_804ad86c = .;
    . = 0x5c0c; arena_804b1754 = .;
    . = 0x5c40; app_804b1788 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
