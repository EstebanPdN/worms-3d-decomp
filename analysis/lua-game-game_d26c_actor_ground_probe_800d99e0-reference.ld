/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d26c_actor_ground_probe_800d99e0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
arena_alloc_801613f0 = 0x801613f0;
cached_id_8015f5a0 = 0x8015f5a0;
data_8040db38 = 0x8040db38;
dir_8043ae38 = 0x8043ae38;
init_800bd920 = 0x800bd920;
post_8016239c = 0x8016239c;
sqrt_802e82c0 = 0x802e82c0;
step_800b0824 = 0x800b0824;
up_8043ae20 = 0x8043ae20;
zero_8045e788 = 0x8045e788;
SECTIONS {
  .text.d26c_actor_ground_probe_800d99e0 0x800d99e0 : { *(.text.d26c_actor_ground_probe_800d99e0) }
  .rodata 0x80389570 : { *(.rodata) }
  .sdata 0x804aeb30 (NOLOAD) : {
    . = 0x0; tick_id_804aeb30 = .;
    . = 0x2c24; arena_804b1754 = .;
    . = 0x2c34; now_804b1764 = .;
    . = 0x2c54; table_ready_804b1784 = .;
    . = 0x2c78; stamp_a_804b17a8 = .;
    . = 0x2c7c; stamp_b_804b17ac = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
