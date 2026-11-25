/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s8_clear_flags_800fdf5c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_80160E34 = 0x80160e34;
SECTIONS {
  .text.s8_clear_flags_800fdf5c 0x800fdf5c : { *(.text.s8_clear_flags_800fdf5c) }
  .sdata 0x804b17f0 (NOLOAD) : {
    . = 0x0; lbl_804B17F0 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
