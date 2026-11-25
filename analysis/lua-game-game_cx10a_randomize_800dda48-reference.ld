/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cx10a_randomize_800dda48)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
center_80389b4c = 0x80389b4c;
multiplier_80389b48 = 0x80389b48;
neutral_80389b50 = 0x80389b50;
random_80162bc8 = 0x80162bc8;
SECTIONS {
  .text.w3d_cx10a_randomize_800dda48 0x800dda48 : { *(.text.w3d_cx10a_randomize_800dda48) }
  .rodata 0x80389b40 : { *(.rodata) }
  .sdata 0x804aec54 (NOLOAD) : {
    . = 0x0; seed_804aec54 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
