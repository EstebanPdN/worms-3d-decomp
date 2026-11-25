/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s19_dispatch_indexed_800bd920)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
FUN_800b6800 = 0x800b6800;
lbl_8043bb64 = 0x8043bb64;
SECTIONS {
  .text.s19_dispatch_indexed_800bd920 0x800bd920 : { *(.text.s19_dispatch_indexed_800bd920) }
  .sdata 0x804b17ac (NOLOAD) : {
    . = 0x0; lbl_804b17ac = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
