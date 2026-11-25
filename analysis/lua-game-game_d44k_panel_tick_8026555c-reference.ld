/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d44k_panel_tick_8026555c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8015ff5c = 0x8015ff5c;
fn_80173df0 = 0x80173df0;
fn_8026807c = 0x8026807c;
fn_802b0668 = 0x802b0668;
fn_8034357c = 0x8034357c;
SECTIONS {
  .text.w3d_d44k_panel_tick_8026555c 0x8026555c : { *(.text.w3d_d44k_panel_tick_8026555c) }
  .rodata 0x803cb56c : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
