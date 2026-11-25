/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(tsonnet_b27_worm_state_8013ea30)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_800fc710 = 0x800fc710;
fn_801190d0 = 0x801190d0;
fn_80139158 = 0x80139158;
fn_80178474 = 0x80178474;
SECTIONS {
  .text.tsonnet_b27_worm_state_8013ea30 0x8013ea30 : { *(.text.tsonnet_b27_worm_state_8013ea30) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
