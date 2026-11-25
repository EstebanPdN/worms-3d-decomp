/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s19_build_masks_8007f95c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
SECTIONS {
  .text.s19_build_masks_8007f95c 0x8007f95c : { *(.text.s19_build_masks_8007f95c) }
  .sdata 0x804adb20 (NOLOAD) : {
    . = 0x0; lbl_804adb20 = .;
    . = 0x4; lbl_804adb24 = .;
    . = 0x2cc; lbl_804addec = .;
    . = 0x2d0; lbl_804addf0 = .;
    . = 0x2d4; lbl_804addf4 = .;
    . = 0x2dc; lbl_804addfc = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
