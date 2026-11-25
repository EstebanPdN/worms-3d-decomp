/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_construct_panel_state_802b2ba4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8015fef0 = 0x8015fef0;
vector_8045e788 = 0x8045e788;
vt_8041c670 = 0x8041c670;
SECTIONS {
  .text.w3d_construct_panel_state_802b2ba4 0x802b2ba4 : { *(.text.w3d_construct_panel_state_802b2ba4) }
  .rodata 0x803d7c88 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
