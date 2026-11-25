/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cx10a_randomize_800dd07c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
center_80389a9c = 0x80389a9c;
multiplier_80389a98 = 0x80389a98;
random_80162bc8 = 0x80162bc8;
zero_80389a88 = 0x80389a88;
SECTIONS {
  .text.w3d_cx10a_randomize_800dd07c 0x800dd07c : { *(.text.w3d_cx10a_randomize_800dd07c) }
  .rodata 0x80389a90 : { *(.rodata) }
  .sdata 0x804aec54 (NOLOAD) : {
    . = 0x0; seed_804aec54 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
