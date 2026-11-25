/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d40h_land_blast_voxels_800b17c4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
clear_8002c70c = 0x8002c70c;
fill_8002c4ec = 0x8002c4ec;
fill_800b2328 = 0x800b2328;
get_800b4d98 = 0x800b4d98;
grid_test_8002c73c = 0x8002c73c;
lbl_8043b044 = 0x8043b044;
lbl_8043bb64 = 0x8043bb64;
memset = 0x802eefe0;
native_80342a78 = 0x80342a78;
pack_800b3fe4 = 0x800b3fe4;
point_800b41c4 = 0x800b41c4;
position_80066894 = 0x80066894;
queue_8008e7d4 = 0x8008e7d4;
queue_8008e9c0 = 0x8008e9c0;
radius_800668ec = 0x800668ec;
reserve_801ef048 = 0x801ef048;
set_80251398 = 0x80251398;
update_80178d28 = 0x80178d28;
value_80178d1c = 0x80178d1c;
SECTIONS {
  .text.d40h_land_blast_voxels_800b17c4 0x800b17c4 : { *(.text.d40h_land_blast_voxels_800b17c4) }
  .rodata 0x80382404 : { *(.rodata) }
  .sdata 0x804ae5dc (NOLOAD) : {
    . = 0x0; lbl_804ae5dc = .;
    . = 0x4; lbl_804ae5e0 = .;
    . = 0x3204; lbl_804b17e0 = .;
    . = 0x324c; lbl_804b1828 = .;
    . = 0x3250; lbl_804b182c = .;
    . = 0x3254; lbl_804b1830 = .;
    . = 0x3258; lbl_804b1834 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
