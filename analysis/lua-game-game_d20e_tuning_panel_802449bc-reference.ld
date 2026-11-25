/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(__15D20eTuningPanelUs)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__10D20eTaggedUs = 0x801ea0ec;
_vt.15D20eTuningPanel = 0x8041b428;
update_8021d0fc__15D20eTuningPanel = 0x8021d0fc;
w3d_empty_string_804b06a0 = 0x804b06a0;
w3d_string_base_init = 0x8020c5c0;
w3d_string_header = 0x80341884;
SECTIONS {
  .text.__15D20eTuningPanelUs 0x802449bc : { *(.text.__15D20eTuningPanelUs) }
  .rodata 0x803c05b4 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
