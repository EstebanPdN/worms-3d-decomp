/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_check_card_802abd94)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
error_803d6ca0 = 0x803d6ca0;
file_803d6c64 = 0x803d6c64;
fn_802ada18 = 0x802ada18;
fn_802fb82c = 0x802fb82c;
SECTIONS {
  .text.w3d_check_card_802abd94 0x802abd94 : { *(.text.w3d_check_card_802abd94) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
