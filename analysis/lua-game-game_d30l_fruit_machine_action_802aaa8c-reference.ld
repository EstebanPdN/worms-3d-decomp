/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d30l_fruit_machine_action_802aaa8c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_80162ba8 = 0x80162ba8;
fn_80165254 = 0x80165254;
fn_80181640 = 0x80181640;
fn_8018179c = 0x8018179c;
fn_802ab24c = 0x802ab24c;
fn_802ab630 = 0x802ab630;
SECTIONS {
  .text.d30l_fruit_machine_action_802aaa8c 0x802aaa8c : { *(.text.d30l_fruit_machine_action_802aaa8c) }
  .rodata 0x803d6a74 : { *(.rodata) }
  .sdata 0x804b1788 (NOLOAD) : {
    . = 0x0; scene_804b1788 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
