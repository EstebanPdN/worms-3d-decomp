/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s20_register_attributes_801c99c8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801e8d9c = 0x801e8d9c;
fn_801ecc6c = 0x801ecc6c;
fn_801eff8c = 0x801eff8c;
lbl_803ad854 = 0x803ad854;
lbl_803ad89c = 0x803ad89c;
lbl_803ad8d4 = 0x803ad8d4;
lbl_803fe630 = 0x803fe630;
lbl_8045d660 = 0x8045d660;
lbl_8045e004 = 0x8045e004;
memset = 0x802eefe0;
SECTIONS {
  .text.w3d_s20_register_attributes_801c99c8 0x801c99c8 : { *(.text.w3d_s20_register_attributes_801c99c8) }
  .sdata 0x804b04e4 (NOLOAD) : {
    . = 0x0; lbl_804b04e4 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
