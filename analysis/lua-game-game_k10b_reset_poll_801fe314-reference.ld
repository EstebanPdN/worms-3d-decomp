/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_k10b_reset_poll_801fe314)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801fe3b0 = 0x801fe3b0;
fn_802fb7ac = 0x802fb7ac;
fn_802fec74 = 0x802fec74;
SECTIONS {
  .text.w3d_k10b_reset_poll_801fe314 0x801fe314 : { *(.text.w3d_k10b_reset_poll_801fe314) }
  .rodata 0x803b2964 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
