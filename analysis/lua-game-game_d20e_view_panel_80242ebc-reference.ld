/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(__13D20eViewPanelUs)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__10D20eTaggedUs = 0x801ea0ec;
_vt.13D20eViewPanel = 0x8041b4c8;
w3d_empty_string_804b06a0 = 0x804b06a0;
w3d_string_base_init = 0x8020c5c0;
w3d_string_header = 0x80341884;
SECTIONS {
  .text.__13D20eViewPanelUs 0x80242ebc : { *(.text.__13D20eViewPanelUs) }
  .rodata 0x803beb80 : { *(.rodata) }
  .sdata 0x804b05a8 (NOLOAD) : {
    . = 0x0; w3d_shared_object_804b05a8 = .;
    . = 0x8; w3d_shared_object_804b05b0 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
