/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d11c_seek_target_80021bb4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__20d11c_String_8020bb54PCc = 0x8020bb54;
d11c_blimp_8036c0fc = 0x8036c0fc;
d11c_camera_set_mode_80035714 = 0x80035714;
d11c_f32_8036c170 = 0x8036c170;
d11c_property_write_800fc43c = 0x800fc43c;
d11c_seek_target_8036c15c = 0x8036c15c;
d11c_string_base_finish_8020c5c4 = 0x8020c5c4;
d11c_string_release_80341588 = 0x80341588;
strcmp = 0x802ef234;
SECTIONS {
  .text.d11c_seek_target_80021bb4 0x80021bb4 : { *(.text.d11c_seek_target_80021bb4) }
  .sdata 0x804aa8c8 (NOLOAD) : {
    . = 0x0; d11c_camera_804aa8c8 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
