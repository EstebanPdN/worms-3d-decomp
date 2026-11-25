/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d27c_camera_side_points_800f1a70)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
norm_801f6c2c = 0x801f6c2c;
SECTIONS {
  .text.d27c_camera_side_points_800f1a70 0x800f1a70 : { *(.text.d27c_camera_side_points_800f1a70) }
  .rodata 0x8038c3e8 : { *(.rodata) }
  .sdata 0x804b1788 (NOLOAD) : {
    . = 0x0; svc_804b1788 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
