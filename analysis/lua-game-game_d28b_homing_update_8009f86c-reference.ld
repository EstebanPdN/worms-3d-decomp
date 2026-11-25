/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d28b_homing_update_8009f86c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
lbl_8043ae20 = 0x8043ae20;
lbl_8045e788 = 0x8045e788;
sqrt_802e82c0 = 0x802e82c0;
w3d_cast_80341584 = 0x80341584;
w3d_weapon_801797b4 = 0x801797b4;
SECTIONS {
  .text.w3d_d28b_homing_update_8009f86c 0x8009f86c : { *(.text.w3d_d28b_homing_update_8009f86c) }
  .rodata 0x80380790 : { *(.rodata) }
  .sdata 0x804b1944 (NOLOAD) : {
    . = 0x0; lbl_804b1944 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
