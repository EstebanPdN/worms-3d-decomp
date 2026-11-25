/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d31g_cell_corner_masks_8007f278)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
SECTIONS {
  .text.w3d_d31g_cell_corner_masks_8007f278 0x8007f278 : { *(.text.w3d_d31g_cell_corner_masks_8007f278) }
  .sdata 0x804adb20 (NOLOAD) : {
    . = 0x0; w3d_mask_a_804adb20 = .;
    . = 0x4; w3d_mask_b_804adb24 = .;
    . = 0x2cc; n0_804addec = .;
    . = 0x2d0; n1_804addf0 = .;
    . = 0x2d4; n2_804addf4 = .;
    . = 0x2d8; n3_804addf8 = .;
    . = 0x2dc; n4_804addfc = .;
    . = 0x2e0; n5_804ade00 = .;
    . = 0x2e4; n6_804ade04 = .;
    . = 0x2e8; n7_804ade08 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
