/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d28l_menu_select_slot_802aa8a4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_80181640 = 0x80181640;
fn_8018179c = 0x8018179c;
fn_801817e0 = 0x801817e0;
fn_80181d00 = 0x80181d00;
SECTIONS {
  .text.d28l_menu_select_slot_802aa8a4 0x802aa8a4 : { *(.text.d28l_menu_select_slot_802aa8a4) }
  .rodata 0x803d6a6c : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
