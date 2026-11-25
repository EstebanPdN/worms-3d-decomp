/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d24g_body_launch_8004b7e0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
init_800b0824 = 0x800b0824;
next_8004b8f4 = 0x8004b8f4;
next_8004cd08 = 0x8004cd08;
start_8043ae20 = 0x8043ae20;
value_80178df0 = 0x80178df0;
SECTIONS {
  .text.w3d_d24g_body_launch_8004b7e0 0x8004b7e0 : { *(.text.w3d_d24g_body_launch_8004b7e0) }
  .rodata 0x80377260 : { *(.rodata) }
  .sdata 0x804b1764 (NOLOAD) : {
    . = 0x0; g_804b1764 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
