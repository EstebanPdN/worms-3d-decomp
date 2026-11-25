/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(__17D20eSettingsPanelUs)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__10D20eTaggedUs = 0x801ea0ec;
_vt.17D20eSettingsPanel = 0x8041b540;
refresh_802487c4__17D20eSettingsPanel = 0x802487c4;
w3d_empty_string_804b06a0 = 0x804b06a0;
w3d_string_base_init = 0x8020c5c0;
w3d_string_header = 0x80341884;
SECTIONS {
  .text.__17D20eSettingsPanelUs 0x80241bac : { *(.text.__17D20eSettingsPanelUs) }
  .rodata 0x803bd420 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
