/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d30l_fruit_machine_update_802a8650)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_80181640 = 0x80181640;
fn_8018179c = 0x8018179c;
fn_80181d00 = 0x80181d00;
fn_802a9058 = 0x802a9058;
fn_802aa8a4 = 0x802aa8a4;
fn_802aaa8c = 0x802aaa8c;
fn_802aaf5c = 0x802aaf5c;
fn_802ab24c = 0x802ab24c;
fn_802b0668 = 0x802b0668;
SECTIONS {
  .text.d30l_fruit_machine_update_802a8650 0x802a8650 : { *(.text.d30l_fruit_machine_update_802a8650) }
  .rodata 0x803d65c4 : { *(.rodata) }
  .sdata 0x804b1788 (NOLOAD) : {
    . = 0x0; scene_804b1788 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
