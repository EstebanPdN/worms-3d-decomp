/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(k4a_shot_power_init_800f1200)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
FUN_801613f0 = 0x801613f0;
s9_permute_80178dfc = 0x80178dfc;
w3d_cached_message_id = 0x8015f5a0;
w3d_constructor_lookup_name = 0x800fc1b0;
w3d_empty_80342a74 = 0x80342a74;
w3d_f32_8038c308 = 0x8038c308;
w3d_message_post_current = 0x8016239c;
w3d_str_8038c2e4 = 0x8038c2e4;
w3d_str_8038c2f0 = 0x8038c2f0;
w3d_subscribe_80162024 = 0x80162024;
w3d_target_id_message_801190b4 = 0x801190b4;
SECTIONS {
  .text.k4a_shot_power_init_800f1200 0x800f1200 : { *(.text.k4a_shot_power_init_800f1200) }
  .sdata 0x804af060 (NOLOAD) : {
    . = 0x0; w3d_message_804af060 = .;
    . = 0x10; w3d_message_804af070 = .;
    . = 0x28; w3d_message_804af088 = .;
    . = 0x26f4; w3d_message_pool_804b1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
