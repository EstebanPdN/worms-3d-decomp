/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d10b_pulse_and_volume_80262154)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
d10b_ambient_803cae80 = 0x803cae80;
d10b_countdown_expired_80262a58 = 0x80262a58;
d10b_music_803cae94 = 0x803cae94;
d10b_peak_803caeb0 = 0x803caeb0;
d10b_period_803caea4 = 0x803caea4;
d10b_phase_step_803caeac = 0x803caeac;
d10b_phase_zero_803caea8 = 0x803caea8;
d10b_read_volume_800fc270 = 0x800fc270;
d10b_scale_803caeb4 = 0x803caeb4;
d10b_sfx_803cae70 = 0x803cae70;
SECTIONS {
  .text.d10b_pulse_and_volume_80262154 0x80262154 : { *(.text.d10b_pulse_and_volume_80262154) }
  .sdata 0x804b1788 (NOLOAD) : {
    . = 0x0; d10b_services_804b1788 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
