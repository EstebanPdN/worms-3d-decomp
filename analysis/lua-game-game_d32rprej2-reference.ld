/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d31l_panel_init_802b0b84)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_800fc1b0 = 0x800fc1b0;
fn_800fd62c = 0x800fd62c;
fn_8015f5a0 = 0x8015f5a0;
fn_80162024 = 0x80162024;
fn_80178c48 = 0x80178c48;
fn_80178d1c = 0x80178d1c;
fn_80179170 = 0x80179170;
fn_8020bd38 = 0x8020bd38;
fn_8020c510 = 0x8020c510;
fn_8020c5c0 = 0x8020c5c0;
fn_8020c5c4 = 0x8020c5c4;
fn_802b192c = 0x802b192c;
fn_802b1d98 = 0x802b1d98;
fn_802b2374 = 0x802b2374;
fn_80341588 = 0x80341588;
fn_80341884 = 0x80341884;
fn_803426b4 = 0x803426b4;
fn_80342a78 = 0x80342a78;
fn_80343744 = 0x80343744;
str_803d79c8 = 0x803d79c8;
str_803d79d4 = 0x803d79d4;
str_803d79e8 = 0x803d79e8;
str_803d79f0 = 0x803d79f0;
strcmp = 0x802ef234;
SECTIONS {
  .text.d31l_panel_init_802b0b84 0x802b0b84 : { *(.text.d31l_panel_init_802b0b84) }
  .sdata 0x804abb60 (NOLOAD) : {
    . = 0x0; font_804abb60 = .;
    . = 0x5420; msg_804b0f80 = .;
    . = 0x5428; msg_804b0f88 = .;
    . = 0x5430; msg_804b0f90 = .;
    . = 0x5438; msg_804b0f98 = .;
    . = 0x5440; msg_804b0fa0 = .;
    . = 0x5448; msg_804b0fa8 = .;
    . = 0x5450; msg_804b0fb0 = .;
    . = 0x5468; msg_804b0fc8 = .;
    . = 0x5470; msg_804b0fd0 = .;
    . = 0x5478; msg_804b0fd8 = .;
    . = 0x5480; msg_804b0fe0 = .;
    . = 0x5488; msg_804b0fe8 = .;
    . = 0x5490; msg_804b0ff0 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
