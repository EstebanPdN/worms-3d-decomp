/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s10_register_properties_801c4068)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801e8d9c = 0x801e8d9c;
fn_801eff8c = 0x801eff8c;
lbl_803aca0c = 0x803aca0c;
lbl_803aca14 = 0x803aca14;
lbl_803fe5a0 = 0x803fe5a0;
lbl_803fe5ac = 0x803fe5ac;
lbl_8045d584 = 0x8045d584;
lbl_8045d598 = 0x8045d598;
lbl_8045e004 = 0x8045e004;
memset = 0x802eefe0;
SECTIONS {
  .text.w3d_s10_register_properties_801c4068 0x801c4068 : { *(.text.w3d_s10_register_properties_801c4068) }
  .sdata 0x804b04b8 (NOLOAD) : {
    . = 0x0; lbl_804b04b8 = .;
    . = 0x4; lbl_804b04bc = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
