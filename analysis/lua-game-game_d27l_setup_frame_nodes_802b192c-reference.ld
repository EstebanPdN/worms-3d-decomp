/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d27l_setup_frame_nodes_802b192c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__3StrPCc = 0x8020bb54;
fn_8015adf4 = 0x8015adf4;
fn_8020c5c4 = 0x8020c5c4;
fn_80341588 = 0x80341588;
front_803d7a74 = 0x803d7a74;
locator_803d7a84 = 0x803d7a84;
null_803d7a6c = 0x803d7a6c;
SECTIONS {
  .text.d27l_setup_frame_nodes_802b192c 0x802b192c : { *(.text.d27l_setup_frame_nodes_802b192c) }
  .rodata 0x803d7a90 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
