/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s9_permute_8014be44)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8015aa04 = 0x8015aa04;
fn_801f67e0 = 0x801f67e0;
SECTIONS {
  .text.s9_permute_8014be44 0x8014be44 : { *(.text.s9_permute_8014be44) }
  .sdata 0x804aa8c8 (NOLOAD) : {
    . = 0x0; lbl_804aa8c8 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
