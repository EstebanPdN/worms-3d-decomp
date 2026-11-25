/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d26c_actor_ground_arrive_800d911c)
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
SECTIONS {
  .text.d26c_actor_ground_arrive_800d911c 0x800d911c : { *(.text.d26c_actor_ground_arrive_800d911c) }
  .rodata 0x80389534 : { *(.rodata) }
  .sdata 0x804aeb08 (NOLOAD) : {
    . = 0x0; arrive_id_804aeb08 = .;
    . = 0x28; tick_id_804aeb30 = .;
    . = 0x2c4c; arena_804b1754 = .;
    . = 0x2c5c; now_804b1764 = .;
    . = 0x2c7c; table_ready_804b1784 = .;
    . = 0x2ca0; stamp_a_804b17a8 = .;
    . = 0x2ca4; stamp_b_804b17ac = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
