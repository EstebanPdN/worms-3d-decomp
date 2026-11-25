/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d25i_trigger_zone_start_80125108)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
arena_alloc_801613f0 = 0x801613f0;
cached_id_8015f5a0 = 0x8015f5a0;
cast_803426b4 = 0x803426b4;
created_init_800c1620 = 0x800c1620;
filter_flags_80125e00 = 0x80125e00;
find_spawn_801254a0 = 0x801254a0;
member_float_8012629c = 0x8012629c;
member_id_80126308 = 0x80126308;
member_slot_801262e4 = 0x801262e4;
member_vec_801262c0 = 0x801262c0;
member_word_8012632c = 0x8012632c;
n_8039b934 = 0x8039b934;
n_8039b944 = 0x8039b944;
n_8039b954 = 0x8039b954;
n_8039b964 = 0x8039b964;
n_8039b978 = 0x8039b978;
n_8039b98c = 0x8039b98c;
n_8039b9a0 = 0x8039b9a0;
n_8039b9b4 = 0x8039b9b4;
n_8039b9cc = 0x8039b9cc;
n_8039b9e0 = 0x8039b9e0;
n_8039b9f8 = 0x8039b9f8;
n_8039ba10 = 0x8039ba10;
n_8039ba20 = 0x8039ba20;
n_8039ba40 = 0x8039ba40;
n_8039ba64 = 0x8039ba64;
post_8016239c = 0x8016239c;
post_text_8012568c = 0x8012568c;
read_float_800fc270 = 0x800fc270;
read_int_800fc1f0 = 0x800fc1f0;
read_key_800fc2b0 = 0x800fc2b0;
read_setting_800fc1b0 = 0x800fc1b0;
subscribe_80162024 = 0x80162024;
SECTIONS {
  .text.d25i_trigger_zone_start_80125108 0x80125108 : { *(.text.d25i_trigger_zone_start_80125108) }
  .rodata 0x8039ba78 : { *(.rodata) }
  .sdata 0x804af544 (NOLOAD) : {
    . = 0x0; cache_804af544 = .;
    . = 0x8; cache_804af54c = .;
    . = 0x2210; arena_804b1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
