/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d30c_rope_start_800ce48c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
arena_alloc_801613f0 = 0x801613f0;
cached_id_8015f5a0 = 0x8015f5a0;
cast_803426b4 = 0x803426b4;
cast_80342a74 = 0x80342a74;
empty_8040db38 = 0x8040db38;
message_init_800c1620 = 0x800c1620;
message_post_8016239c = 0x8016239c;
n_80387f00 = 0x80387f00;
n_80387f14 = 0x80387f14;
n_80387f28 = 0x80387f28;
n_80387f30 = 0x80387f30;
n_80387f48 = 0x80387f48;
n_80387f58 = 0x80387f58;
n_80387f68 = 0x80387f68;
n_80387f78 = 0x80387f78;
n_80387f94 = 0x80387f94;
n_80387fb0 = 0x80387fb0;
n_80387fc8 = 0x80387fc8;
n_80387fe4 = 0x80387fe4;
n_80388000 = 0x80388000;
n_80388014 = 0x80388014;
n_80388034 = 0x80388034;
n_80388044 = 0x80388044;
n_80388060 = 0x80388060;
n_80388078 = 0x80388078;
read_int_800fc1f0 = 0x800fc1f0;
read_setting_800fc1b0 = 0x800fc1b0;
subscribe_80162024 = 0x80162024;
target_init_801190b4 = 0x801190b4;
timer_mode_801262e4 = 0x801262e4;
timer_owner_80126308 = 0x80126308;
timer_rate_8012632c = 0x8012632c;
timer_time_8012629c = 0x8012629c;
write_float_800fc4c8 = 0x800fc4c8;
SECTIONS {
  .text.d30c_rope_start_800ce48c 0x800ce48c : { *(.text.d30c_rope_start_800ce48c) }
  .rodata 0x80388088 : { *(.rodata) }
  .sdata 0x804ae890 (NOLOAD) : {
    . = 0x0; cache_804ae890 = .;
    . = 0x8; cache_804ae898 = .;
    . = 0x18; cache_804ae8a8 = .;
    . = 0x20; cache_804ae8b0 = .;
    . = 0x28; cache_804ae8b8 = .;
    . = 0x38; cache_804ae8c8 = .;
    . = 0x48; cache_804ae8d8 = .;
    . = 0x50; cache_804ae8e0 = .;
    . = 0x58; cache_804ae8e8 = .;
    . = 0x60; cache_804ae8f0 = .;
    . = 0x68; cache_804ae8f8 = .;
    . = 0x70; cache_804ae900 = .;
    . = 0x78; cache_804ae908 = .;
    . = 0x80; cache_804ae910 = .;
    . = 0x88; cache_804ae918 = .;
    . = 0x90; cache_804ae920 = .;
    . = 0x98; cache_804ae928 = .;
    . = 0xa0; cache_804ae930 = .;
    . = 0xf0; cache_804ae980 = .;
    . = 0xf8; cache_804ae988 = .;
    . = 0x118; cache_804ae9a8 = .;
    . = 0x2ec4; g_arena_804b1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
