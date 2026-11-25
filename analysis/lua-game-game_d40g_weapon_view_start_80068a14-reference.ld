/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d40g_weapon_view_start_80068a14)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__6StringPCc = 0x8020bb54;
acquire_80162024 = 0x80162024;
arena_alloc_801613f0 = 0x801613f0;
camera_8006947c = 0x8006947c;
cast_803426b4 = 0x803426b4;
deactivate_8015fd1c = 0x8015fd1c;
hands_800697ac = 0x800697ac;
index_80178c48 = 0x80178c48;
keys_803eb63c = 0x803eb63c;
load_80068eac = 0x80068eac;
lookup_800fc1b0 = 0x800fc1b0;
message_id_8015f5a0 = 0x8015f5a0;
message_post_8016239c = 0x8016239c;
model_cast_80343584 = 0x80343584;
read_int_800fc230 = 0x800fc230;
read_prop_800fc330 = 0x800fc330;
s_8037a858 = 0x8037a858;
s_8037a884 = 0x8037a884;
s_8037a894 = 0x8037a894;
s_8037a898 = 0x8037a898;
s_8037a8a8 = 0x8037a8a8;
set_name_8015adf4 = 0x8015adf4;
strcmp = 0x802ef234;
string_assign_8020bd38 = 0x8020bd38;
string_finish_8020c5c4 = 0x8020c5c4;
string_header_80341884 = 0x80341884;
string_init_8020c5c0 = 0x8020c5c0;
string_release_80341588 = 0x80341588;
string_release_header_8020bb2c = 0x8020bb2c;
target_message_801190b4 = 0x801190b4;
worm_800fc6dc = 0x800fc6dc;
SECTIONS {
  .text.d40g_weapon_view_start_80068a14 0x80068a14 : { *(.text.d40g_weapon_view_start_80068a14) }
  .sdata 0x804ad628 (NOLOAD) : {
    . = 0x0; msg_804ad628 = .;
    . = 0x8; msg_804ad630 = .;
    . = 0x10; msg_804ad638 = .;
    . = 0x28; msg_804ad650 = .;
    . = 0x30; msg_804ad658 = .;
    . = 0x38; msg_804ad660 = .;
    . = 0x40; msg_804ad668 = .;
    . = 0x412c; arena_804b1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
