/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d41h_clock_tick_sound_800a2e78)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
lbl_80380c84 = 0x80380c84;
lbl_80380ca0 = 0x80380ca0;
SECTIONS {
  .text.d41h_clock_tick_sound_800a2e78 0x800a2e78 : { *(.text.d41h_clock_tick_sound_800a2e78) }
  .rodata 0x80380ca8 : { *(.rodata) }
  .sdata 0x804b1788 (NOLOAD) : {
    . = 0x0; g_services_804b1788 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
