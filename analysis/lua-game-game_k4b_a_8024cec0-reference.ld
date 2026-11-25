/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_k4b_widget_construct_8024cec0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
lbl_8041b870 = 0x8041b870;
w3d_auto_8024cd0c = 0x8024cd0c;
SECTIONS {
  .text.w3d_k4b_widget_construct_8024cec0 0x8024cec0 : { *(.text.w3d_k4b_widget_construct_8024cec0) }
  .rodata 0x803c4c94 : { *(.rodata) }
  .sdata 0x804b05a8 (NOLOAD) : {
    . = 0x0; lbl_804b05a8 = .;
    . = 0x4; lbl_804b05ac = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
