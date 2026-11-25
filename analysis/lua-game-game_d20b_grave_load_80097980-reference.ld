/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d20b_grave_load_80097980)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__20d20b_String_8020bb54PCc = 0x8020bb54;
d20b_active_worm_8037f668 = 0x8037f668;
d20b_as_mesh_80343584 = 0x80343584;
d20b_check_control_8018179c = 0x8018179c;
d20b_grave_brown_8037f6c8 = 0x8037f6c8;
d20b_grave_eye_8037f654 = 0x8037f654;
d20b_grave_flame_8037f694 = 0x8037f694;
d20b_grave_marble_8037f6e0 = 0x8037f6e0;
d20b_grave_obelisk_8037f6ac = 0x8037f6ac;
d20b_grave_pyramid_8037f678 = 0x8037f678;
d20b_handle_load_8015adf4 = 0x8015adf4;
d20b_heap_allocate_802098d8 = 0x802098d8;
d20b_main_brown_8037f6d4 = 0x8037f6d4;
d20b_main_eye_8037f660 = 0x8037f660;
d20b_main_flame_8037f6a0 = 0x8037f6a0;
d20b_main_marble_8037f6f0 = 0x8037f6f0;
d20b_main_obelisk_8037f6bc = 0x8037f6bc;
d20b_main_pyramid_8037f688 = 0x8037f688;
d20b_member_attach_80126610 = 0x80126610;
d20b_member_init_kind_8012656c = 0x8012656c;
d20b_member_set_scale_80126688 = 0x80126688;
d20b_play_clip_80181640 = 0x80181640;
d20b_setting_read_800fc1f0 = 0x800fc1f0;
d20b_string_finish_8020c5c4 = 0x8020c5c4;
d20b_string_release_80341588 = 0x80341588;
SECTIONS {
  .text.d20b_grave_load_80097980 0x80097980 : { *(.text.d20b_grave_load_80097980) }
  .rodata 0x8037f6fc : { *(.rodata) }
  .sdata 0x804af5bc (NOLOAD) : {
    . = 0x0; d20b_member_heap_804af5bc = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
