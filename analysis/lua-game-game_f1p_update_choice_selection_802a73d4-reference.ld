/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_update_choice_selection_802a73d4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_80178c48 = 0x80178c48;
fn_80178d1c = 0x80178d1c;
fn_8020c5c0 = 0x8020c5c0;
fn_8028496c = 0x8028496c;
fn_80341884 = 0x80341884;
fn_803426b4 = 0x803426b4;
fn_80342a78 = 0x80342a78;
SECTIONS {
  .text.w3d_update_choice_selection_802a73d4 0x802a73d4 : { *(.text.w3d_update_choice_selection_802a73d4) }
  .sdata 0x804abbac (NOLOAD) : {
    . = 0x0; table_804abbac = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
