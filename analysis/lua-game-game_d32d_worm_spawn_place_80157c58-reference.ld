/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d32d_worm_spawn_place_80157c58)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
_._19Descriptor_80178474 = 0x80178474;
_._6Handle = 0x80126230;
__15String_803426b8 = 0x803426b8;
__6Handle = 0x80126184;
alloc_801613f0 = 0x801613f0;
atan2_802e7e5c = 0x802e7e5c;
axis_801f7538 = 0x801f7538;
center_803a2c5c = 0x803a2c5c;
empty_80342fa4 = 0x80342fa4;
euler_801a3eb0 = 0x801a3eb0;
frandom_80162bc8 = 0x80162bc8;
handle_800fc710 = 0x800fc710;
handle_mask_8012632c = 0x8012632c;
handle_next_801264fc = 0x801264fc;
handle_pos_801262c0 = 0x801262c0;
handle_radius_8012629c = 0x8012629c;
handle_reset_80126524 = 0x80126524;
handle_run_80126334 = 0x80126334;
handle_slot_801262e4 = 0x801262e4;
id_8015f5a0 = 0x8015f5a0;
init_800683fc = 0x800683fc;
memcpy_802eee50 = 0x802eee50;
next_8001dd28 = 0x8001dd28;
post_8016239c = 0x8016239c;
random_80162ba8 = 0x80162ba8;
read_float_800fc270 = 0x800fc270;
read_vec_800fc2f0 = 0x800fc2f0;
record12_at_80343bb4 = 0x80343bb4;
sample_8001e224 = 0x8001e224;
spawn_803a2c3c = 0x803a2c3c;
strcmp = 0x802ef234;
string_base_init_8020c5c0 = 0x8020c5c0;
string_finish_8020c5c4 = 0x8020c5c4;
string_header_80341884 = 0x80341884;
string_release_80341588 = 0x80341588;
vec_80178ec4 = 0x80178ec4;
zoffset_803a2c44 = 0x803a2c44;
SECTIONS {
  .text.w3d_d32d_worm_spawn_place_80157c58 0x80157c58 : { *(.text.w3d_d32d_worm_spawn_place_80157c58) }
  .rodata 0x803a2c68 : { *(.rodata) }
  .sdata 0x804afe90 (NOLOAD) : {
    . = 0x0; id_804afe90 = .;
    . = 0x18c4; heap_804b1754 = .;
    . = 0x18c8; grid_804b1758 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
