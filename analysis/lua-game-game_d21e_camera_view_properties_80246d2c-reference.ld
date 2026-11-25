/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d21e_register_camera_view_properties_80246d2c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
desc_803c33cc = 0x803c33cc;
desc_803c3400 = 0x803c3400;
desc_803c3430 = 0x803c3430;
desc_803c3464 = 0x803c3464;
desc_803c34a4 = 0x803c34a4;
desc_803c34d8 = 0x803c34d8;
desc_803c3514 = 0x803c3514;
fn_801e8d9c = 0x801e8d9c;
fn_801ebf38 = 0x801ebf38;
fn_801ec52c = 0x801ec52c;
fn_801f254c = 0x801f254c;
lbl_803c353c = 0x803c353c;
lbl_8045e494 = 0x8045e494;
memset = 0x802eefe0;
SECTIONS {
  .text.w3d_d21e_register_camera_view_properties_80246d2c 0x80246d2c : { *(.text.w3d_d21e_register_camera_view_properties_80246d2c) }
  .bss 0x80464d9c : { *(.bss) }
  .sbss 0x804b0880 : { *(.sbss) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
