/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cx14b_sound_voice_start_801e4994)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
advance_801e47e8 = 0x801e47e8;
close_802f5320 = 0x802f5320;
data_80324224 = 0x80324224;
range_803238fc = 0x803238fc;
rate_80324e7c = 0x80324e7c;
start_80325bb8 = 0x80325bb8;
voice_80324920 = 0x80324920;
SECTIONS {
  .text.w3d_cx14b_sound_voice_start_801e4994 0x801e4994 : { *(.text.w3d_cx14b_sound_voice_start_801e4994) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
