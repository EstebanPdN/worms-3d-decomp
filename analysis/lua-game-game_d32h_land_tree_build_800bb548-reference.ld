/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d32h_land_tree_build_800bb548)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__6Stream = 0x80207fec;
__6StringPCc = 0x8020bb54;
allocate_80212fd4 = 0x80212fd4;
append_801ef174 = 0x801ef174;
bounds_800b7ed0 = 0x800b7ed0;
box_sphere_801f55ec = 0x801f55ec;
cast_80342a74 = 0x80342a74;
copy_802eee50 = 0x802eee50;
copy_transform_800b8ca0 = 0x800b8ca0;
count_800bb4e4 = 0x800bb4e4;
create_8020b680 = 0x8020b680;
empty_8045e690 = 0x8045e690;
get_800b4d98 = 0x800b4d98;
heap_allocate_802098d8 = 0x802098d8;
key_80414160 = 0x80414160;
key_80418f78 = 0x80418f78;
land_acquire_800b1394 = 0x800b1394;
land_ctor_800b12c8 = 0x800b12c8;
land_load_800b2408 = 0x800b2408;
lands_8043bb64 = 0x8043bb64;
position_800b7ec4 = 0x800b7ec4;
position_ctor_80343740 = 0x80343740;
release_802134fc = 0x802134fc;
select_800ba4c4 = 0x800ba4c4;
set_index_800b7ebc = 0x800b7ebc;
sqrt_802e82c0 = 0x802e82c0;
strcmp = 0x802ef234;
stream_close_8020810c = 0x8020810c;
stream_finish_8020803c = 0x8020803c;
stream_open_802080a0 = 0x802080a0;
string_finish_8020c5c4 = 0x8020c5c4;
string_release_80341588 = 0x80341588;
type_8040e078 = 0x8040e078;
value_80178df0 = 0x80178df0;
SECTIONS {
  .text.d32h_land_tree_build_800bb548 0x800bb548 : { *(.text.d32h_land_tree_build_800bb548) }
  .rodata 0x80382ba0 : { *(.rodata) }
  .sdata 0x804aad30 (NOLOAD) : {
    . = 0x0; selection_804aad30 = .;
    . = 0x30b4; heap_804adde4 = .;
    . = 0x38a8; scale_804ae5d8 = .;
    . = 0x38b4; array_804ae5e4 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
