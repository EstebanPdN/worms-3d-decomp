/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s19_test_cell_800bd954)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
FUN_8002c73c = 0x8002c73c;
lbl_8043bb64 = 0x8043bb64;
w3d_get_800b4d98 = 0x800b4d98;
SECTIONS {
  .text.s19_test_cell_800bd954 0x800bd954 : { *(.text.s19_test_cell_800bd954) }
  .sdata 0x804b1798 (NOLOAD) : {
    . = 0x0; lbl_804b1798 = .;
    . = 0x4; lbl_804b179c = .;
    . = 0x8; lbl_804b17a0 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
