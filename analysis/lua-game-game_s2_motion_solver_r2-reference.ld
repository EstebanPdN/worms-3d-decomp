/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_motion_set_target_801182c0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_fn_800d75f0 = 0x800d75f0;
w3d_motion_height_time_80118aac = 0x80118aac;
SECTIONS {
  .text.w3d_motion_set_target_801182c0 0x801182c0 : { *(.text.w3d_motion_set_target_801182c0) }
  .text.w3d_motion_at_height_80118a5c 0x80118a5c : { *(.text.w3d_motion_at_height_80118a5c) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
