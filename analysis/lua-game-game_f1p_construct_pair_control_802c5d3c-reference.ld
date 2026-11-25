/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_construct_pair_control_802c5d3c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8015fef0 = 0x8015fef0;
vector_8045e788 = 0x8045e788;
vt_8041c920 = 0x8041c920;
zero_803d8cfc = 0x803d8cfc;
SECTIONS {
  .text.w3d_construct_pair_control_802c5d3c 0x802c5d3c : { *(.text.w3d_construct_pair_control_802c5d3c) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
