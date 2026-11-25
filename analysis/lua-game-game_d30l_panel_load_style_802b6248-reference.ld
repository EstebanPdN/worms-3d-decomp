/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d30l_panel_load_style_802b6248)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_800fc1b0 = 0x800fc1b0;
fn_800fd62c = 0x800fd62c;
fn_8015f5a0 = 0x8015f5a0;
fn_80162024 = 0x80162024;
fn_80165254 = 0x80165254;
fn_80178c48 = 0x80178c48;
fn_80178d1c = 0x80178d1c;
fn_80178df0 = 0x80178df0;
fn_80179170 = 0x80179170;
fn_8020bb2c = 0x8020bb2c;
fn_8020c510 = 0x8020c510;
fn_8020c5c0 = 0x8020c5c0;
fn_8020c5c4 = 0x8020c5c4;
fn_802b0b84 = 0x802b0b84;
fn_802b6c44 = 0x802b6c44;
fn_802b6da8 = 0x802b6da8;
fn_802b6efc = 0x802b6efc;
fn_802b8418 = 0x802b8418;
fn_802b8be0 = 0x802b8be0;
fn_802b9ae0 = 0x802b9ae0;
fn_80341588 = 0x80341588;
fn_80341884 = 0x80341884;
fn_803426b4 = 0x803426b4;
fn_803426b8 = 0x803426b8;
fn_80342a74 = 0x80342a74;
fn_80342a78 = 0x80342a78;
fn_80343744 = 0x80343744;
fn_80343df4 = 0x80343df4;
s_803d7f6c = 0x803d7f6c;
s_803d7f80 = 0x803d7f80;
s_803d7f90 = 0x803d7f90;
s_803d7fd0 = 0x803d7fd0;
s_803d7ff4 = 0x803d7ff4;
zero_803d7ff8 = 0x803d7ff8;
SECTIONS {
  .text.d30l_panel_load_style_802b6248 0x802b6248 : { *(.text.d30l_panel_load_style_802b6248) }
  .sdata 0x804b1058 (NOLOAD) : {
    . = 0x0; msg_804b1058 = .;
    . = 0x8; msg_804b1060 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
