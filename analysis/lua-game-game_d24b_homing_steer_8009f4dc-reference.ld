/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d24b_homing_steer_8009f4dc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_as_weapon_801797b4 = 0x801797b4;
w3d_identity_80341584 = 0x80341584;
w3d_sqrtf_802e82c0 = 0x802e82c0;
SECTIONS {
  .text.w3d_d24b_homing_steer_8009f4dc 0x8009f4dc : { *(.text.w3d_d24b_homing_steer_8009f4dc) }
  .rodata 0x80380778 : { *(.rodata) }
  .sdata 0x804b1944 (NOLOAD) : {
    . = 0x0; w3d_frame_time_804b1944 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
