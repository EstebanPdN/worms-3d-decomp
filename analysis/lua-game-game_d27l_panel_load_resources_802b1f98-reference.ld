/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d27l_panel_load_resources_802b1f98)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8020c5c0 = 0x8020c5c0;
fn_8020c5c4 = 0x8020c5c4;
fn_802b1cec = 0x802b1cec;
fn_802b24bc = 0x802b24bc;
fn_802b2664__5PanelG3Stri = 0x802b2664;
fn_80341588 = 0x80341588;
fn_80341884 = 0x80341884;
SECTIONS {
  .text.d27l_panel_load_resources_802b1f98 0x802b1f98 : { *(.text.d27l_panel_load_resources_802b1f98) }
  .rodata 0x803d7ae8 : { *(.rodata) }
  .sdata 0x804abb58 (NOLOAD) : {
    . = 0x0; id_804abb58 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
