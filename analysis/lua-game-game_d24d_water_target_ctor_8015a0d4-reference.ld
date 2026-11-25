/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(__16d24d_WaterTargetPCci)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__20d24d_String_803426b8 = 0x803426b8;
_vt.16d24d_WaterTarget = 0x80410ff0;
assign__20d24d_String_803426b8PCc = 0x8020bd38;
d24d_active_worm_803a41c8 = 0x803a41c8;
d24d_camera_mode_803a41b4 = 0x803a41b4;
d24d_setting_lookup_800fc1b0 = 0x800fc1b0;
d24d_view_a_80342a78 = 0x80342a78;
d24d_view_b_803426b4 = 0x803426b4;
d24d_view_c_80342a74 = 0x80342a74;
d24d_water_level_803a41f0 = 0x803a41f0;
d24d_water_target_803a41d8 = 0x803a41d8;
SECTIONS {
  .text.__16d24d_WaterTargetPCci 0x8015a0d4 : { *(.text.__16d24d_WaterTargetPCci) }
  .rodata 0x803a41fc : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
