/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d27l_panel_set_enabled_802b0990)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_80178d1c = 0x80178d1c;
fn_80178d28 = 0x80178d28;
fn_8018179c = 0x8018179c;
fn_8020c5c0 = 0x8020c5c0;
fn_8020c5c4 = 0x8020c5c4;
fn_80264698 = 0x80264698;
fn_802b1cec = 0x802b1cec;
fn_802b2164 = 0x802b2164;
fn_802b21ec = 0x802b21ec;
fn_80341588 = 0x80341588;
fn_80341884 = 0x80341884;
fn_80342a78 = 0x80342a78;
fn_80343584 = 0x80343584;
SECTIONS {
  .text.d27l_panel_set_enabled_802b0990 0x802b0990 : { *(.text.d27l_panel_set_enabled_802b0990) }
  .sdata 0x804abb44 (NOLOAD) : {
    . = 0x0; rename_804abb44 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
