/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cx11a_command_finish_80009984)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
append_80008d84 = 0x80008d84;
divisor_803695b0 = 0x803695b0;
multiplier_803695b4 = 0x803695b4;
release_800089c8 = 0x800089c8;
SECTIONS {
  .text.w3d_cx11a_command_finish_80009984 0x80009984 : { *(.text.w3d_cx11a_command_finish_80009984) }
  .rodata 0x803695a8 : { *(.rodata) }
  .sdata 0x804aa574 (NOLOAD) : {
    . = 0x0; ticks_804aa574 = .;
    . = 0x18; mode_804aa58c = .;
    . = 0x164; settings_804aa6d8 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
