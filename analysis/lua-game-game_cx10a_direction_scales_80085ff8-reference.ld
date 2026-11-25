/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cx10a_direction_scales_80085ff8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
constant_8037cf34 = 0x8037cf34;
constant_8037cf38 = 0x8037cf38;
constant_8037cf3c = 0x8037cf3c;
constant_8037cf40 = 0x8037cf40;
SECTIONS {
  .text.w3d_cx10a_direction_scales_80085ff8 0x80085ff8 : { *(.text.w3d_cx10a_direction_scales_80085ff8) }
  .sdata 0x804adaf4 (NOLOAD) : {
    . = 0x0; output_804adaf4 = .;
    . = 0x4; output_804adaf8 = .;
    . = 0x8; output_804adafc = .;
    . = 0xc; output_804adb00 = .;
    . = 0x10; output_804adb04 = .;
    . = 0x14; output_804adb08 = .;
    . = 0x18; output_804adb0c = .;
    . = 0x1c; output_804adb10 = .;
    . = 0x2f8; flags_804addec = .;
    . = 0x304; flags_804addf8 = .;
    . = 0x308; flags_804addfc = .;
    . = 0x314; flags_804ade08 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
