/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s11_lua_random_802dff20)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_802CD7F4 = 0x802cd7f4;
fn_802CDF40 = 0x802cdf40;
fn_802DCC74 = 0x802dcc74;
fn_802DCE74 = 0x802dce74;
fn_802DD10C = 0x802dd10c;
fn_802E75D0 = 0x802e75d0;
fn_802EE7DC = 0x802ee7dc;
lbl_803DAE80 = 0x803dae80;
lbl_803DAE94 = 0x803dae94;
SECTIONS {
  .text.s11_lua_random_802dff20 0x802dff20 : { *(.text.s11_lua_random_802dff20) }
  .rodata 0x803daeb0 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
