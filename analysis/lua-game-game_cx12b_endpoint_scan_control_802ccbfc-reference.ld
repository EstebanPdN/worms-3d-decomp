/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cx12b_endpoint_scan_control_802ccbfc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
active_80473724 = 0x80473724;
control_802cccbc = 0x802cccbc;
endpoints_804738a4 = 0x804738a4;
find_802eed00 = 0x802eed00;
SECTIONS {
  .text.w3d_cx12b_endpoint_scan_control_802ccbfc 0x802ccbfc : { *(.text.w3d_cx12b_endpoint_scan_control_802ccbfc) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
