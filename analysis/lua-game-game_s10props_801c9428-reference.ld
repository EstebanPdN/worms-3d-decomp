/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s10_register_properties_801c9428)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801e8d9c = 0x801e8d9c;
fn_801eff8c = 0x801eff8c;
lbl_803ad844 = 0x803ad844;
lbl_803ad854 = 0x803ad854;
lbl_803fe624 = 0x803fe624;
lbl_803fe630 = 0x803fe630;
lbl_8045d624 = 0x8045d624;
lbl_8045d638 = 0x8045d638;
lbl_8045e004 = 0x8045e004;
memset = 0x802eefe0;
SECTIONS {
  .text.w3d_s10_register_properties_801c9428 0x801c9428 : { *(.text.w3d_s10_register_properties_801c9428) }
  .sdata 0x804b04d8 (NOLOAD) : {
    . = 0x0; lbl_804b04d8 = .;
    . = 0x4; lbl_804b04dc = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
