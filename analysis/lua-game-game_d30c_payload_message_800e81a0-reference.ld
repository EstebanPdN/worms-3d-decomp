/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d30c_payload_message_800e81a0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
base_8015fb34 = 0x8015fb34;
cast_801797b4 = 0x801797b4;
check_8018179c = 0x8018179c;
clip_800e96d8 = 0x800e96d8;
empty_80341584 = 0x80341584;
find_800e8f40 = 0x800e8f40;
flag_800e8ee0 = 0x800e8ee0;
notify_800e8a88 = 0x800e8a88;
play_800e99cc = 0x800e99cc;
same_8015f65c = 0x8015f65c;
scene_800e9e04 = 0x800e9e04;
start_800e8bb0 = 0x800e8bb0;
stopped_800e88e0 = 0x800e88e0;
strcmp_802ef234 = 0x802ef234;
string_finish_8020c5c4 = 0x8020c5c4;
string_header_80341884 = 0x80341884;
string_init_8020c5c0 = 0x8020c5c0;
string_release_80341588 = 0x80341588;
value_80125ff8 = 0x80125ff8;
write_800fc43c = 0x800fc43c;
SECTIONS {
  .text.d30c_payload_message_800e81a0 0x800e81a0 : { *(.text.d30c_payload_message_800e81a0) }
  .rodata 0x8038b1f8 : { *(.rodata) }
  .sdata 0x804aee58 (NOLOAD) : {
    . = 0x0; c58_804aee58 = .;
    . = 0x8; c60_804aee60 = .;
    . = 0x10; c68_804aee68 = .;
    . = 0x20; c78_804aee78 = .;
    . = 0x28; c80_804aee80 = .;
    . = 0x30; c88_804aee88 = .;
    . = 0x38; c90_804aee90 = .;
    . = 0x40; c98_804aee98 = .;
    . = 0x48; ca0_804aeea0 = .;
    . = 0x50; ca8_804aeea8 = .;
    . = 0x58; cb0_804aeeb0 = .;
    . = 0x60; cb8_804aeeb8 = .;
    . = 0x68; cc0_804aeec0 = .;
    . = 0x2930; manager_804b1788 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
