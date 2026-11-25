/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s20_register_properties_801c9d00)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801e8d9c = 0x801e8d9c;
fn_801ec52c = 0x801ec52c;
fn_801ecc6c = 0x801ecc6c;
fn_801eff8c = 0x801eff8c;
lbl_803ad854 = 0x803ad854;
lbl_803ad91c = 0x803ad91c;
lbl_803ad954 = 0x803ad954;
lbl_803ad978 = 0x803ad978;
lbl_803ad9ac = 0x803ad9ac;
lbl_803ad9e0 = 0x803ad9e0;
lbl_803ada10 = 0x803ada10;
lbl_803ada44 = 0x803ada44;
lbl_803ada78 = 0x803ada78;
lbl_803adab0 = 0x803adab0;
lbl_803adae8 = 0x803adae8;
lbl_803fe630 = 0x803fe630;
lbl_8045d674 = 0x8045d674;
lbl_8045e004 = 0x8045e004;
memset = 0x802eefe0;
SECTIONS {
  .text.w3d_s20_register_properties_801c9d00 0x801c9d00 : { *(.text.w3d_s20_register_properties_801c9d00) }
  .sdata 0x804b04e8 (NOLOAD) : {
    . = 0x0; lbl_804b04e8 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
