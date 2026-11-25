/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d28j_find_root_8019727c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
eval_80197244 = 0x80197244;
SECTIONS {
  .text.d28j_find_root_8019727c 0x8019727c : { *(.text.d28j_find_root_8019727c) }
  .rodata 0x803a84f8 : { *(.rodata) }
  .sdata 0x804ab6e4 (NOLOAD) : {
    . = 0x0; lbl_804ab6e4 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
