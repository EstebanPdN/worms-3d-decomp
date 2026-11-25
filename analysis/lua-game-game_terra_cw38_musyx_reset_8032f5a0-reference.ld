/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(terra_cw38_musyx_reset_8032f5a0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
SECTIONS {
  .text.terra_cw38_musyx_reset_8032f5a0 0x8032f5a0 : { *(.text.terra_cw38_musyx_reset_8032f5a0) }
  .sdata 0x804b1620 (NOLOAD) : {
    . = 0x0; musyx_state_804b1620 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
