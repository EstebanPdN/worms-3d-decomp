/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d31g_landmark_setup_800601a0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__4Vec2 = 0x80343740;
__6String = 0x803426b8;
as_mesh_80343584 = 0x80343584;
create_8020b680 = 0x8020b680;
heap_802098d8 = 0x802098d8;
init_8012656c = 0x8012656c;
k_80379178 = 0x80379178;
make_800e5ca4 = 0x800e5ca4;
mesh_status_80182408 = 0x80182408;
pair_800b8c50 = 0x800b8c50;
place_8009ed90 = 0x8009ed90;
pos_800b43f8 = 0x800b43f8;
rot_801f6120 = 0x801f6120;
rot_801f61a0 = 0x801f61a0;
rot_801f621c = 0x801f621c;
s_80379168 = 0x80379168;
s_80379170 = 0x80379170;
set_801265ec = 0x801265ec;
set_80126610 = 0x80126610;
set_80126688 = 0x80126688;
set_name_8015adf4 = 0x8015adf4;
strcmp_802ef234 = 0x802ef234;
string_finish_8020c5c4 = 0x8020c5c4;
string_header_release_8020bb2c = 0x8020bb2c;
string_prefix_8020c048 = 0x8020c048;
string_release_80341588 = 0x80341588;
string_suffix_8020c0fc = 0x8020c0fc;
string_upper_8020c2e8 = 0x8020c2e8;
theme_800606e4 = 0x800606e4;
type_80413a68 = 0x80413a68;
SECTIONS {
  .text.w3d_d31g_landmark_setup_800601a0 0x800601a0 : { *(.text.w3d_d31g_landmark_setup_800601a0) }
  .sdata 0x804af5bc (NOLOAD) : {
    . = 0x0; heap_804af5bc = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
