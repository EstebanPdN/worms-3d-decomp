/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_hit_simple_802b9cf4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_802b22e4 = 0x802b22e4;
SECTIONS {
  .text.w3d_hit_simple_802b9cf4 0x802b9cf4 : { *(.text.w3d_hit_simple_802b9cf4) }
  .sdata 0x804abb4c (NOLOAD) : {
    . = 0x0; state_804abb4c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
