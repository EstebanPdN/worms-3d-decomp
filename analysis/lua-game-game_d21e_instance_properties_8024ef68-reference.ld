/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d21e_register_instance_properties_8024ef68)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
d20e_empty_804b06a0 = 0x804b06a0;
d20e_release_header_8020bb2c = 0x8020bb2c;
d20e_string_finish_8020c5c4 = 0x8020c5c4;
d20e_string_header_80341884 = 0x80341884;
d20e_string_init_8020c5c0 = 0x8020c5c0;
d20e_string_release_80341588 = 0x80341588;
desc_803c557c = 0x803c557c;
fn_801e8d9c = 0x801e8d9c;
fn_801ed24c = 0x801ed24c;
fn_801efdfc = 0x801efdfc;
lbl_803c553c = 0x803c553c;
lbl_8045ed4c = 0x8045ed4c;
memset = 0x802eefe0;
SECTIONS {
  .text.w3d_d21e_register_instance_properties_8024ef68 0x8024ef68 : { *(.text.w3d_d21e_register_instance_properties_8024ef68) }
  .bss 0x80464fcc : { *(.bss) }
  .sbss 0x804b08f0 : { *(.sbss) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
