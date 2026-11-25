/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d17c_oil_drum_load_800d54b8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__20d17c_String_8020bb54PCc = 0x8020bb54;
d17c_as_node_80343584 = 0x80343584;
d17c_check_control_8018179c = 0x8018179c;
d17c_follow_owner_800d56bc = 0x800d56bc;
d17c_handle_load_8015adf4 = 0x8015adf4;
d17c_heap_allocate_802098d8 = 0x802098d8;
d17c_member_attach_80126610 = 0x80126610;
d17c_member_init_kind_8012656c = 0x8012656c;
d17c_oil_drum_80388d90 = 0x80388d90;
d17c_play_clip_80181640 = 0x80181640;
d17c_publish_worm_count_801555f8 = 0x801555f8;
d17c_read_uint_800fc230 = 0x800fc230;
d17c_string_finish_8020c5c4 = 0x8020c5c4;
d17c_string_release_80341588 = 0x80341588;
d17c_worm_count_80388db8 = 0x80388db8;
SECTIONS {
  .text.d17c_oil_drum_load_800d54b8 0x800d54b8 : { *(.text.d17c_oil_drum_load_800d54b8) }
  .rodata 0x80388df0 : { *(.rodata) }
  .sdata 0x804aae54 (NOLOAD) : {
    . = 0x0; d17c_idle_clip_804aae54 = .;
    . = 0x5ac; d17c_worm_count_804ab400 = .;
    . = 0x4768; d17c_member_heap_804af5bc = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
