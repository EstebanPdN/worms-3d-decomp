/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cx11a_random_pair_800dce48)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
center_80389a6c = 0x80389a6c;
multiplier_80389a68 = 0x80389a68;
neutral_80389a70 = 0x80389a70;
random_80162bc8 = 0x80162bc8;
SECTIONS {
  .text.w3d_cx11a_random_pair_800dce48 0x800dce48 : { *(.text.w3d_cx11a_random_pair_800dce48) }
  .rodata 0x80389a60 : { *(.rodata) }
  .sdata 0x804aec54 (NOLOAD) : {
    . = 0x0; seed_804aec54 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
