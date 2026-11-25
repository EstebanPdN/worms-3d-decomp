/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d33g_camera_aim_limits_80071e30)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
eval_800d75f0 = 0x800d75f0;
g_8042ff68 = 0x8042ff68;
sqrt_802e82c0 = 0x802e82c0;
SECTIONS {
  .text.w3d_d33g_camera_aim_limits_80071e30 0x80071e30 : { *(.text.w3d_d33g_camera_aim_limits_80071e30) }
  .rodata 0x8037caf8 : { *(.rodata) }
  .sdata 0x804aaaec (NOLOAD) : {
    . = 0x0; flip_804aaaec = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
