/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d27l_panel_text_line_802b509c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__3Str = 0x803426b8;
fn_800fc1b0 = 0x800fc1b0;
fn_801790bc = 0x801790bc;
fn_80179170 = 0x80179170;
fn_8020bb2c = 0x8020bb2c;
fn_8020bd38 = 0x8020bd38;
fn_8020c3a0 = 0x8020c3a0;
fn_8020c510 = 0x8020c510;
fn_8020c5c0 = 0x8020c5c0;
fn_8020c5c4 = 0x8020c5c4;
fn_80341588 = 0x80341588;
fn_80341884 = 0x80341884;
fn_80343744 = 0x80343744;
s_803d7e4c = 0x803d7e4c;
s_803d7e84 = 0x803d7e84;
s_803d7e88 = 0x803d7e88;
strcspn = 0x802ef380;
SECTIONS {
  .text.d27l_panel_text_line_802b509c 0x802b509c : { *(.text.d27l_panel_text_line_802b509c) }
  .sdata 0x804b1788 (NOLOAD) : {
    . = 0x0; settings_804b1788 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
