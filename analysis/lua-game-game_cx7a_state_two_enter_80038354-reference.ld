/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cx7a_state_two_enter_80038354)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
clock_801fe45c = 0x801fe45c;
refresh_8003864c = 0x8003864c;
value_80178df0 = 0x80178df0;
SECTIONS {
  .text.w3d_cx7a_state_two_enter_80038354 0x80038354 : { *(.text.w3d_cx7a_state_two_enter_80038354) }
  .rodata 0x80373fb0 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
