/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s12_init_string_property_8019aeb8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801e8d9c = 0x801e8d9c;
fn_801ecc6c = 0x801ecc6c;
fn_801ed24c = 0x801ed24c;
fn_801eff8c = 0x801eff8c;
fn_8020bb2c = 0x8020bb2c;
fn_8020c5c0 = 0x8020c5c0;
fn_8020c5c4 = 0x8020c5c4;
fn_80341588 = 0x80341588;
fn_80341884 = 0x80341884;
lbl_803a9498 = 0x803a9498;
lbl_803a94cc = 0x803a94cc;
lbl_803a94f0 = 0x803a94f0;
lbl_803fe92c = 0x803fe92c;
lbl_8045ccf8 = 0x8045ccf8;
lbl_8045e004 = 0x8045e004;
lbl_804b06a0 = 0x804b06a0;
memset = 0x802eefe0;
SECTIONS {
  .text.w3d_s12_init_string_property_8019aeb8 0x8019aeb8 : { *(.text.w3d_s12_init_string_property_8019aeb8) }
  .sdata 0x804b02f4 (NOLOAD) : {
    . = 0x0; lbl_804b02f4 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
