/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cx10a_randomize_800dcfc0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
center_80389a84 = 0x80389a84;
multiplier_80389a80 = 0x80389a80;
random_80162bc8 = 0x80162bc8;
SECTIONS {
  .text.w3d_cx10a_randomize_800dcfc0 0x800dcfc0 : { *(.text.w3d_cx10a_randomize_800dcfc0) }
  .rodata 0x80389a78 : { *(.rodata) }
  .sdata 0x804aec54 (NOLOAD) : {
    . = 0x0; seed_804aec54 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
