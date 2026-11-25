/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(__14D20eLargePanelUs)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__9D20ePanelUs = 0x80251f40;
_vt.14D20eLargePanel = 0x8041ba90;
w3d_empty_string_804b06a0 = 0x804b06a0;
w3d_string_base_init = 0x8020c5c0;
w3d_string_header = 0x80341884;
SECTIONS {
  .text.__14D20eLargePanelUs 0x80253330 : { *(.text.__14D20eLargePanelUs) }
  .rodata 0x803c6714 : { *(.rodata) }
  .sdata 0x804b05b0 (NOLOAD) : {
    . = 0x0; w3d_shared_object_804b05b0 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
