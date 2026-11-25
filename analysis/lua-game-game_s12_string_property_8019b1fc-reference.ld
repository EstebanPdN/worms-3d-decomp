/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s12_init_string_property_8019b1fc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801e8d9c = 0x801e8d9c;
fn_801ec52c = 0x801ec52c;
fn_801ed24c = 0x801ed24c;
fn_801eff8c = 0x801eff8c;
fn_8020bb2c = 0x8020bb2c;
fn_8020c5c0 = 0x8020c5c0;
fn_8020c5c4 = 0x8020c5c4;
fn_80341588 = 0x80341588;
fn_80341884 = 0x80341884;
lbl_803a9500 = 0x803a9500;
lbl_803a9530 = 0x803a9530;
lbl_803a9558 = 0x803a9558;
lbl_803fe938 = 0x803fe938;
lbl_8045cd0c = 0x8045cd0c;
lbl_8045e004 = 0x8045e004;
lbl_804b06a0 = 0x804b06a0;
memset = 0x802eefe0;
SECTIONS {
  .text.w3d_s12_init_string_property_8019b1fc 0x8019b1fc : { *(.text.w3d_s12_init_string_property_8019b1fc) }
  .sdata 0x804b02f8 (NOLOAD) : {
    . = 0x0; lbl_804b02f8 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
