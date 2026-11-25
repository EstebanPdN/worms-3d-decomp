/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d41a_bomber_aim_update_800374f8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
acos_802e7c30 = 0x802e7c30;
w3d_auto_800edf7c = 0x800edf7c;
w3d_auto_800fc2f0 = 0x800fc2f0;
w3d_engine_get_context_80165254 = 0x80165254;
w3d_fn_802e82c0 = 0x802e82c0;
w3d_s20_lookup_handle_80164fc8 = 0x80164fc8;
w3d_zero_8045e788 = 0x8045e788;
SECTIONS {
  .text.w3d_d41a_bomber_aim_update_800374f8 0x800374f8 : { *(.text.w3d_d41a_bomber_aim_update_800374f8) }
  .rodata 0x80373e24 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
