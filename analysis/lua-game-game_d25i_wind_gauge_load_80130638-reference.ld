/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d25i_wind_gauge_load_80130638)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__6StringPCc = 0x8020bb54;
as_float_80342a74 = 0x80342a74;
as_mesh_8034380c = 0x8034380c;
as_vector_80342fa4 = 0x80342fa4;
cached_id_8015f5a0 = 0x8015f5a0;
digits_80130e24 = 0x80130e24;
load_8015adf4 = 0x8015adf4;
mesh_alloc_8018920c = 0x8018920c;
mesh_colours_80189760 = 0x80189760;
mesh_lock_80189450 = 0x80189450;
n_8039e010 = 0x8039e010;
n_8039e020 = 0x8039e020;
n_8039e030 = 0x8039e030;
n_8039e040 = 0x8039e040;
n_8039e054 = 0x8039e054;
n_8039e068 = 0x8039e068;
n_8039e078 = 0x8039e078;
n_8039e090 = 0x8039e090;
n_8039e0a4 = 0x8039e0a4;
n_8039e0bc = 0x8039e0bc;
n_8039e0d0 = 0x8039e0d0;
n_8039e0e8 = 0x8039e0e8;
n_8039e100 = 0x8039e100;
n_8039e114 = 0x8039e114;
n_8039e120 = 0x8039e120;
n_8039e130 = 0x8039e130;
n_8039e140 = 0x8039e140;
n_8039e150 = 0x8039e150;
ratio_80130d1c = 0x80130d1c;
read_colour_800fc370 = 0x800fc370;
read_setting_800fc1b0 = 0x800fc1b0;
set_scale_80130fb8 = 0x80130fb8;
string_finish_8020c5c4 = 0x8020c5c4;
string_release_80341588 = 0x80341588;
subscribe_80162024 = 0x80162024;
value_of_80178ec4 = 0x80178ec4;
SECTIONS {
  .text.d25i_wind_gauge_load_80130638 0x80130638 : { *(.text.d25i_wind_gauge_load_80130638) }
  .rodata 0x8039e158 : { *(.rodata) }
  .sdata 0x804af730 (NOLOAD) : {
    . = 0x0; cache_804af730 = .;
    . = 0x8; cache_804af738 = .;
    . = 0x2058; services_804b1788 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
