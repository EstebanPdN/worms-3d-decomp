/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(cc39b_session_state_8028dc30)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cc39b_clock_80165254 = 0x80165254;
cc39b_state_reset_8028d34c = 0x8028d34c;
cc39b_state_stop_8028d3b8 = 0x8028d3b8;
SECTIONS {
  .text.cc39b_session_state_8028dc30 0x8028dc30 : { *(.text.cc39b_session_state_8028dc30) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
