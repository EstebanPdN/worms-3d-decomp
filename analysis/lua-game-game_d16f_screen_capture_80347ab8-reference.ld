/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d16f_screen_capture_a_80347ab8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
d16f_file_system_8020b884 = 0x8020b884;
d16f_format_into_80347a10 = 0x80347a10;
d16f_name_pattern_803a4514 = 0x803a4514;
d16f_name_pattern_803a4574 = 0x803a4574;
d16f_service_get_8020b680 = 0x8020b680;
d16f_surface_descriptor_80415cc0 = 0x80415cc0;
d16f_surface_encode_801a4d68 = 0x801a4d68;
d16f_surface_prepare_801afac0 = 0x801afac0;
SECTIONS {
  .text.d16f_screen_capture_a_80347ab8 0x80347ab8 : { *(.text.d16f_screen_capture_a_80347ab8) }
  .text.d16f_screen_capture_b_80348f2c 0x80348f2c : { *(.text.d16f_screen_capture_b_80348f2c) }
  .sdata 0x804ab464 (NOLOAD) : {
    . = 0x0; d16f_capture_counter_804ab464 = .;
    . = 0xc; d16f_capture_counter_804ab470 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
