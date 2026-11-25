/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d24g_frontend_start_8006ba08)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
add_800c4b00 = 0x800c4b00;
arena_alloc_801613f0 = 0x801613f0;
count_800c4660 = 0x800c4660;
create_80164514 = 0x80164514;
default_name_80127da4 = 0x80127da4;
language_80127b48 = 0x80127b48;
maintain_8006e6c8 = 0x8006e6c8;
message_id_8015f5a0 = 0x8015f5a0;
message_int_800a82f0 = 0x800a82f0;
message_post_8016239c = 0x8016239c;
message_string_8010a8e0 = 0x8010a8e0;
prepare_8006eebc = 0x8006eebc;
read_int_800fc1f0 = 0x800fc1f0;
s_8037bb14 = 0x8037bb14;
s_8037bd3c = 0x8037bd3c;
s_8037be30 = 0x8037be30;
s_8037be44 = 0x8037be44;
s_8037be58 = 0x8037be58;
step_800a7ea0 = 0x800a7ea0;
trim_800c4e18 = 0x800c4e18;
type_8020b680 = 0x8020b680;
type_8040f240 = 0x8040f240;
type_8040f9d8 = 0x8040f9d8;
type_8040fa18 = 0x8040fa18;
type_8040fa58 = 0x8040fa58;
type_804100a8 = 0x804100a8;
type_80410898 = 0x80410898;
type_8041bae0 = 0x8041bae0;
type_8041bbb0 = 0x8041bbb0;
type_8041c1a0 = 0x8041c1a0;
type_8041c1e0 = 0x8041c1e0;
type_8041c260 = 0x8041c260;
vt_8040db38 = 0x8040db38;
write_int_800fc3b0 = 0x800fc3b0;
SECTIONS {
  .text.w3d_d24g_frontend_start_8006ba08 0x8006ba08 : { *(.text.w3d_d24g_frontend_start_8006ba08) }
  .sdata 0x804ad744 (NOLOAD) : {
    . = 0x0; msg_804ad744 = .;
    . = 0x8; msg_804ad74c = .;
    . = 0x10; msg_804ad754 = .;
    . = 0x48; msg_804ad78c = .;
    . = 0x4010; arena_804b1754 = .;
    . = 0x4044; app_804b1788 = .;
    . = 0x4048; service_804b178c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
