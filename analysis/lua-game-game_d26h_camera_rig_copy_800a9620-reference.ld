/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d26h_camera_rig_copy_800a9620)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
arena_alloc_801613f0 = 0x801613f0;
base_8015a6b8 = 0x8015a6b8;
message_id_8015f5a0 = 0x8015f5a0;
message_init_8010a8e0 = 0x8010a8e0;
message_post_8016239c = 0x8016239c;
sqrt_802e82c0 = 0x802e82c0;
SECTIONS {
  .text.d26h_camera_rig_copy_800a9620 0x800a9620 : { *(.text.d26h_camera_rig_copy_800a9620) }
  .rodata 0x80381914 : { *(.rodata) }
  .sdata 0x804ab420 (NOLOAD) : {
    . = 0x0; g_804ab420 = .;
    . = 0x2eec; id_804ae30c = .;
    . = 0x2ef4; id_804ae314 = .;
    . = 0x6334; g_arena_804b1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
