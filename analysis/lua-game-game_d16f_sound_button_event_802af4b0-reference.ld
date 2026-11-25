/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(handle_event__15D16fSoundButtonP9D16fEvent)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
d16f_base_event_8015fb34 = 0x8015fb34;
d16f_button_start_802af894 = 0x802af894;
d16f_button_stop_802af924 = 0x802af924;
d16f_control_event_802aff9c = 0x802aff9c;
d16f_control_ready_802b264c = 0x802b264c;
d16f_message_id_equals_8015f65c = 0x8015f65c;
d16f_play_sound_802b1258 = 0x802b1258;
SECTIONS {
  .text.handle_event__15D16fSoundButtonP9D16fEvent 0x802af4b0 : { *(.text.handle_event__15D16fSoundButtonP9D16fEvent) }
  .sdata 0x804abb48 (NOLOAD) : {
    . = 0x0; d16f_input_locked_804abb48 = .;
    . = 0x53e4; d16f_id_804b0f2c = .;
    . = 0x53ec; d16f_id_804b0f34 = .;
    . = 0x53f4; d16f_id_804b0f3c = .;
    . = 0x53fc; d16f_id_804b0f44 = .;
    . = 0x5404; d16f_id_804b0f4c = .;
    . = 0x540c; d16f_id_804b0f54 = .;
    . = 0x5414; d16f_id_804b0f5c = .;
    . = 0x541c; d16f_id_804b0f64 = .;
    . = 0x5424; d16f_id_804b0f6c = .;
    . = 0x542c; d16f_id_804b0f74 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
