/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(tsonnet_c33_poll_dispatch_801fdbec)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801fde88 = 0x801fde88;
fn_801fe314 = 0x801fe314;
fn_802f76e0 = 0x802f76e0;
fn_80344278 = 0x80344278;
SECTIONS {
  .text.tsonnet_c33_poll_dispatch_801fdbec 0x801fdbec : { *(.text.tsonnet_c33_poll_dispatch_801fdbec) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
