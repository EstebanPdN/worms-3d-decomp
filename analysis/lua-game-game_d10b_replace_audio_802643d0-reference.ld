/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d10b_replace_audio_802643d0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
d10b_read_float_800fc270 = 0x800fc270;
d10b_volume_key_803cae70 = 0x803cae70;
SECTIONS {
  .text.d10b_replace_audio_802643d0 0x802643d0 : { *(.text.d10b_replace_audio_802643d0) }
  .sdata 0x804b1788 (NOLOAD) : {
    . = 0x0; d10b_services_804b1788 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
