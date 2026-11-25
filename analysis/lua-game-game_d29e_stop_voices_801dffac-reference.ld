/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d29e_stop_voices_801dffac)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_auto_801e4e6c = 0x801e4e6c;
w3d_get_801df288 = 0x801df288;
SECTIONS {
  .text.w3d_d29e_stop_voices_801dffac 0x801dffac : { *(.text.w3d_d29e_stop_voices_801dffac) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
