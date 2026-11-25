/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d27l_fit_box_to_items_802c196c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_800fc1b0 = 0x800fc1b0;
fn_801797b4 = 0x801797b4;
fn_8020c5c4 = 0x8020c5c4;
fn_80341584 = 0x80341584;
fn_80341588 = 0x80341588;
type_80365c68 = 0x80365c68;
SECTIONS {
  .text.d27l_fit_box_to_items_802c196c 0x802c196c : { *(.text.d27l_fit_box_to_items_802c196c) }
  .rodata 0x803d8538 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
