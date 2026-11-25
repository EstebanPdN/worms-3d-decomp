/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_auto_80015d04)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
lbl_8036A64C = 0x8036a64c;
lbl_8040DB38 = 0x8040db38;
lbl_80417630 = 0x80417630;
lbl_80417778 = 0x80417778;
lbl_80418D48 = 0x80418d48;
SECTIONS {
  .text.w3d_auto_80015d04 0x80015d04 : { *(.text.w3d_auto_80015d04) }
  .text.w3d_auto_800361f8 0x800361f8 : { *(.text.w3d_auto_800361f8) }
  .text.w3d_auto_800a8314 0x800a8314 : { *(.text.w3d_auto_800a8314) }
  .text.w3d_auto_801eb058 0x801eb058 : { *(.text.w3d_auto_801eb058) }
  .text.w3d_auto_801ede78 0x801ede78 : { *(.text.w3d_auto_801ede78) }
  .text.w3d_auto_801ffe44 0x801ffe44 : { *(.text.w3d_auto_801ffe44) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
