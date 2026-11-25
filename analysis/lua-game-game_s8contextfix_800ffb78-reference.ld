/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s8_destroy_string_buffer_800ffb78)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_800FFBE0 = 0x800ffbe0;
fn_80209920 = 0x80209920;
fn_8020C5C4 = 0x8020c5c4;
fn_802134FC = 0x802134fc;
fn_80341588 = 0x80341588;
SECTIONS {
  .text.s8_destroy_string_buffer_800ffb78 0x800ffb78 : { *(.text.s8_destroy_string_buffer_800ffb78) }
  .sdata 0x804af15c (NOLOAD) : {
    . = 0x0; lbl_804AF15C = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
