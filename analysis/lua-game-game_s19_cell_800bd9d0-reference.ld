/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s19_apply_cell_800bd9d0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
FUN_800b46bc = 0x800b46bc;
lbl_8043bb64 = 0x8043bb64;
w3d_auto_80178d1c = 0x80178d1c;
w3d_constructor_native_cast = 0x80342a78;
SECTIONS {
  .text.s19_apply_cell_800bd9d0 0x800bd9d0 : { *(.text.s19_apply_cell_800bd9d0) }
  .sdata 0x804ae5e0 (NOLOAD) : {
    . = 0x0; lbl_804ae5e0 = .;
    . = 0x3274; lbl_804b1854 = .;
    . = 0x3278; lbl_804b1858 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
