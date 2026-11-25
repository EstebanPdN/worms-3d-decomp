/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(k4a_laser_beam_init_8009af20)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_cached_message_id = 0x8015f5a0;
w3d_handle_set_name = 0x8015adf4;
w3d_str_80380000 = 0x80380000;
w3d_string_base_finish = 0x8020c5c4;
w3d_string_from_text = 0x8020bb54;
w3d_string_release = 0x80341588;
w3d_subscribe_80162024 = 0x80162024;
SECTIONS {
  .text.k4a_laser_beam_init_8009af20 0x8009af20 : { *(.text.k4a_laser_beam_init_8009af20) }
  .sdata 0x804adfc4 (NOLOAD) : {
    . = 0x0; w3d_message_804adfc4 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
