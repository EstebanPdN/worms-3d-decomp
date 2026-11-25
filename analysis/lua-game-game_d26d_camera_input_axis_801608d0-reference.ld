/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d26d_camera_input_axis_801608d0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
alloc_801613f0 = 0x801613f0;
post_8015fc84 = 0x8015fc84;
type_8040db38 = 0x8040db38;
SECTIONS {
  .text.d26d_camera_input_axis_801608d0 0x801608d0 : { *(.text.d26d_camera_input_axis_801608d0) }
  .rodata 0x803a4668 : { *(.rodata) }
  .sdata 0x804b1754 (NOLOAD) : {
    . = 0x0; heap_804b1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
