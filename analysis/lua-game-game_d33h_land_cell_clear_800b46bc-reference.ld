/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d33h_land_cell_clear_800b46bc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
clear_8002c70c = 0x8002c70c;
fill_8002c4ec = 0x8002c4ec;
fill_800b2328 = 0x800b2328;
get_800b4d98 = 0x800b4d98;
lbl_8043bb64 = 0x8043bb64;
pack_800b3fe4 = 0x800b3fe4;
queue_8008e7d4 = 0x8008e7d4;
queue_8008e9c0 = 0x8008e9c0;
reserve_801ef048 = 0x801ef048;
set_80251398 = 0x80251398;
SECTIONS {
  .text.d33h_land_cell_clear_800b46bc 0x800b46bc : { *(.text.d33h_land_cell_clear_800b46bc) }
  .sdata 0x804b1828 (NOLOAD) : {
    . = 0x0; lbl_804b1828 = .;
    . = 0x4; lbl_804b182c = .;
    . = 0x8; lbl_804b1830 = .;
    . = 0xc; lbl_804b1834 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
