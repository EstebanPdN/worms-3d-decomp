/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_setup_list_element_802bd158)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__20F1pListText_8020bb54PCc = 0x8020bb54;
fn_800fc1b0 = 0x800fc1b0;
fn_8015adf4 = 0x8015adf4;
fn_8020c5c4 = 0x8020c5c4;
fn_802bd4fc = 0x802bd4fc;
fn_802bdd24 = 0x802bdd24;
fn_80341588 = 0x80341588;
fn_80342a74 = 0x80342a74;
key_803d8368 = 0x803d8368;
text_803d8360 = 0x803d8360;
SECTIONS {
  .text.w3d_setup_list_element_802bd158 0x802bd158 : { *(.text.w3d_setup_list_element_802bd158) }
  .rodata 0x803d8388 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
