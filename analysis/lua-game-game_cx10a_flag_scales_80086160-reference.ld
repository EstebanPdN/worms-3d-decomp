/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cx10a_flag_scales_80086160)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
constant_8037cf44 = 0x8037cf44;
constant_8037cf48 = 0x8037cf48;
SECTIONS {
  .text.w3d_cx10a_flag_scales_80086160 0x80086160 : { *(.text.w3d_cx10a_flag_scales_80086160) }
  .sdata 0x804adb38 (NOLOAD) : {
    . = 0x0; output_804adb38 = .;
    . = 0x4; output_804adb3c = .;
    . = 0x8; output_804adb40 = .;
    . = 0xc; output_804adb44 = .;
    . = 0x10; output_804adb48 = .;
    . = 0x14; output_804adb4c = .;
    . = 0x18; output_804adb50 = .;
    . = 0x1c; output_804adb54 = .;
    . = 0x2b4; flags_804addec = .;
    . = 0x2b8; flags_804addf0 = .;
    . = 0x2bc; flags_804addf4 = .;
    . = 0x2c0; flags_804addf8 = .;
    . = 0x2c4; flags_804addfc = .;
    . = 0x2c8; flags_804ade00 = .;
    . = 0x2cc; flags_804ade04 = .;
    . = 0x2d0; flags_804ade08 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
