/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_e14a_begin_marked_region_800b11dc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
lbl_8043add8 = 0x8043add8;
s19_visit_marked_800bd794 = 0x800bd794;
SECTIONS {
  .text.w3d_e14a_begin_marked_region_800b11dc 0x800b11dc : { *(.text.w3d_e14a_begin_marked_region_800b11dc) }
  .sdata 0x804b1764 (NOLOAD) : {
    . = 0x0; lbl_804b1764 = .;
    . = 0x20; lbl_804b1784 = .;
    . = 0x7c; lbl_804b17e0 = .;
    . = 0xac; lbl_804b1810 = .;
    . = 0xb0; lbl_804b1814 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
