/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_k4b_named_range_construct_801c9f2c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
lbl_804162f8 = 0x804162f8;
w3d_k4b_named_construct_801c90c0 = 0x801c90c0;
SECTIONS {
  .text.w3d_k4b_named_range_construct_801c9f2c 0x801c9f2c : { *(.text.w3d_k4b_named_range_construct_801c9f2c) }
  .rodata 0x803adb20 : { *(.rodata) }
  .sdata 0x804b05ac (NOLOAD) : {
    . = 0x0; lbl_804b05ac = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
