/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d29g_earthquake_start_80061a80)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
d24d_acquire_message_80162024 = 0x80162024;
data_8040db38 = 0x8040db38;
s0_8037930c = 0x8037930c;
s1_80379318 = 0x80379318;
s2_80379334 = 0x80379334;
s3_80379354 = 0x80379354;
s4_8037936c = 0x8037936c;
s5_80379380 = 0x80379380;
s6_80379394 = 0x80379394;
s7_803793b0 = 0x803793b0;
s8_803793b8 = 0x803793b8;
s8_property_write_800fc3b0 = 0x800fc3b0;
s8_property_write_800fc43c = 0x800fc43c;
tsonnet_b33_arena_801613f0 = 0x801613f0;
type_a_80361860 = 0x80361860;
type_b_803618f0 = 0x803618f0;
w3d_assert_80022e20 = 0x80022e20;
w3d_auto_800fc1f0 = 0x800fc1f0;
w3d_auto_800fc230 = 0x800fc230;
w3d_auto_800fc270 = 0x800fc270;
w3d_cached_message_id = 0x8015f5a0;
w3d_cx7a_service_float_assign_800fc4c8 = 0x800fc4c8;
w3d_message_post_current = 0x8016239c;
w3d_s20_forward_global4_800fdd80 = 0x800fdd80;
w3d_sound_80035714 = 0x80035714;
zero_8045e788 = 0x8045e788;
SECTIONS {
  .text.w3d_d29g_earthquake_start_80061a80 0x80061a80 : { *(.text.w3d_d29g_earthquake_start_80061a80) }
  .rodata 0x803793cc : { *(.rodata) }
  .sdata 0x804aa8c8 (NOLOAD) : {
    . = 0x0; sound_804aa8c8 = .;
    . = 0x2c2c; m0_804ad4f4 = .;
    . = 0x2c34; m1_804ad4fc = .;
    . = 0x6e8c; arena_804b1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
