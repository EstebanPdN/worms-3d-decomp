/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d26h_land_messages_800bab30)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__6String = 0x803426b8;
__6StringPCc = 0x8020bb54;
a_800bd954 = 0x800bd954;
arena_alloc_801613f0 = 0x801613f0;
b_800bd9d0 = 0x800bd9d0;
base_handler_8015fb34 = 0x8015fb34;
broadcast_800bdc44 = 0x800bdc44;
c_800bd920 = 0x800bd920;
cache_equals_8015f620 = 0x8015f620;
clear_800bb3a0 = 0x800bb3a0;
collide_800bda28 = 0x800bda28;
g_8044bec0 = 0x8044bec0;
g_8044becc = 0x8044becc;
grid_800be3a0 = 0x800be3a0;
held_get_800f34f0 = 0x800f34f0;
held_release_800f34a0 = 0x800f34a0;
load_held_800bc7c4 = 0x800bc7c4;
load_other_800bc350 = 0x800bc350;
load_xom_800bc5d0 = 0x800bc5d0;
message_id_8015f5a0 = 0x8015f5a0;
message_post_8016239c = 0x8016239c;
msg_text_8010a8fc = 0x8010a8fc;
shutdown_800be980 = 0x800be980;
start_800bb114 = 0x800bb114;
strcmp_802ef234 = 0x802ef234;
string_finish_8020c5c4 = 0x8020c5c4;
string_release_80341588 = 0x80341588;
string_suffix_8020c0fc = 0x8020c0fc;
string_upper_8020c2e8 = 0x8020c2e8;
t_8040db38 = 0x8040db38;
SECTIONS {
  .text.d26h_land_messages_800bab30 0x800bab30 : { *(.text.d26h_land_messages_800bab30) }
  .rodata 0x80382b1c : { *(.rodata) }
  .sdata 0x804ae580 (NOLOAD) : {
    . = 0x0; c_804ae580 = .;
    . = 0x8; c_804ae588 = .;
    . = 0x10; c_804ae590 = .;
    . = 0x20; c_804ae5a0 = .;
    . = 0x28; c_804ae5a8 = .;
    . = 0x30; c_804ae5b0 = .;
    . = 0x40; c_804ae5c0 = .;
    . = 0x48; c_804ae5c8 = .;
    . = 0x50; c_804ae5d0 = .;
    . = 0x31d4; g_arena_804b1754 = .;
    . = 0x32cc; g_804b184c = .;
    . = 0x32d0; g_804b1850 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
