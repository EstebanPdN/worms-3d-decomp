/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d21e_register_lens_flare_properties_80245ac8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
desc_803c23d4 = 0x803c23d4;
desc_803c2408 = 0x803c2408;
desc_803c243c = 0x803c243c;
fn_801e8d9c = 0x801e8d9c;
fn_801eb674 = 0x801eb674;
fn_801ec52c = 0x801ec52c;
fn_801eff8c = 0x801eff8c;
lbl_803c2464 = 0x803c2464;
lbl_803f4540 = 0x803f4540;
lbl_8045e004 = 0x8045e004;
memset = 0x802eefe0;
SECTIONS {
  .text.w3d_d21e_register_lens_flare_properties_80245ac8 0x80245ac8 : { *(.text.w3d_d21e_register_lens_flare_properties_80245ac8) }
  .bss 0x80464d88 : { *(.bss) }
  .sbss 0x804b087c : { *(.sbss) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
