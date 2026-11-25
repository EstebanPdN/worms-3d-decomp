/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s19_camera_ctor_800520f4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
FUN_800d2dec = 0x800d2dec;
lbl_8040eb90 = 0x8040eb90;
w3d_auto_800d31d8 = 0x800d31d8;
SECTIONS {
  .text.s19_camera_ctor_800520f4 0x800520f4 : { *(.text.s19_camera_ctor_800520f4) }
  .rodata 0x8037824c : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
