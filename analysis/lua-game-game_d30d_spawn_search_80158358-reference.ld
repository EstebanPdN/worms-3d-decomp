/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d30d_spawn_search_80158358)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
alloc_801613f0 = 0x801613f0;
alloc_80212fd4 = 0x80212fd4;
cast_80342fa4 = 0x80342fa4;
free_802134fc = 0x802134fc;
get_vec_80178ec4 = 0x80178ec4;
hit_8043ae20 = 0x8043ae20;
memcpy = 0x802eee50;
message_id_8015f5a0 = 0x8015f5a0;
message_init_800683fc = 0x800683fc;
normal_8043ae38 = 0x8043ae38;
post_8016239c = 0x8016239c;
read_float_800fc270 = 0x800fc270;
set_vec_80178fa4 = 0x80178fa4;
spawn_803a2c3c = 0x803a2c3c;
sqrtf_802e82c0 = 0x802e82c0;
sweep_800b0824 = 0x800b0824;
trace_800bd920 = 0x800bd920;
water_803a2bf8 = 0x803a2bf8;
zero_8045e788 = 0x8045e788;
SECTIONS {
  .text.d30d_spawn_search_80158358 0x80158358 : { *(.text.d30d_spawn_search_80158358) }
  .rodata 0x803a2c9c : { *(.rodata) }
  .sdata 0x804afe90 (NOLOAD) : {
    . = 0x0; cache_804afe90 = .;
    . = 0x18c4; heap_804b1754 = .;
    . = 0x18d4; hits_804b1764 = .;
    . = 0x18f4; traceReady_804b1784 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
