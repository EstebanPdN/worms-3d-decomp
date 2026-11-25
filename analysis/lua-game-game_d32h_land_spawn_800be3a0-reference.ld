/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d32h_land_spawn_800be3a0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__6StringPCc = 0x8020bb54;
allocate_80212fd4 = 0x80212fd4;
append_801ef174 = 0x801ef174;
attach_800b87d0 = 0x800b87d0;
bounds_800b7ed0 = 0x800b7ed0;
copy_802eee50 = 0x802eee50;
create_8020b680 = 0x8020b680;
euler_801a3eb0 = 0x801a3eb0;
get_800b4d98 = 0x800b4d98;
heap_allocate_802098d8 = 0x802098d8;
key_80413b28 = 0x80413b28;
land_ctor_800b12c8 = 0x800b12c8;
lands_8043bb64 = 0x8043bb64;
load_8015adf4 = 0x8015adf4;
owner_80182150 = 0x80182150;
position_ctor_80343740 = 0x80343740;
release_802134fc = 0x802134fc;
select_800ba4c4 = 0x800ba4c4;
set_index_800b7ebc = 0x800b7ebc;
sqrt_802e82c0 = 0x802e82c0;
string_finish_8020c5c4 = 0x8020c5c4;
string_release_80341588 = 0x80341588;
type_8040e078 = 0x8040e078;
SECTIONS {
  .text.d32h_land_spawn_800be3a0 0x800be3a0 : { *(.text.d32h_land_spawn_800be3a0) }
  .rodata 0x80382d18 : { *(.rodata) }
  .sdata 0x804aad30 (NOLOAD) : {
    . = 0x0; selection_804aad30 = .;
    . = 0x30b4; heap_804adde4 = .;
    . = 0x38b4; array_804ae5e4 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
