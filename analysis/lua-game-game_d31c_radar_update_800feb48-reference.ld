/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d31c_radar_update_800feb48)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
as_mesh_8034380c = 0x8034380c;
atan2_802e7e5c = 0x802e7e5c;
axis_801f7538 = 0x801f7538;
cast_803426b4 = 0x803426b4;
colour_800fd388 = 0x800fd388;
colours_80189760 = 0x80189760;
flags_80189704 = 0x80189704;
fvalue_80178df0 = 0x80178df0;
invert_801f74d0 = 0x801f74d0;
lerp_800ff97c = 0x800ff97c;
marker_800ff56c = 0x800ff56c;
normalize_801f6c2c = 0x801f6c2c;
positions_80189518 = 0x80189518;
radar_800ff6a4 = 0x800ff6a4;
sqrt_802e82c0 = 0x802e82c0;
value_80178c48 = 0x80178c48;
vec_ctor_80343740 = 0x80343740;
worm_800fc6dc = 0x800fc6dc;
SECTIONS {
  .text.d31c_radar_update_800feb48 0x800feb48 : { *(.text.d31c_radar_update_800feb48) }
  .rodata 0x80398280 : { *(.rodata) }
  .sdata 0x804b1788 (NOLOAD) : {
    . = 0x0; manager_804b1788 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
