/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s10_register_properties_801cb170)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801e8d9c = 0x801e8d9c;
fn_801efd98 = 0x801efd98;
fn_801efdfc = 0x801efdfc;
lbl_803add34 = 0x803add34;
lbl_803add40 = 0x803add40;
lbl_803add50 = 0x803add50;
lbl_8045d778 = 0x8045d778;
lbl_8045d78c = 0x8045d78c;
lbl_8045d7a0 = 0x8045d7a0;
lbl_8045ed34 = 0x8045ed34;
lbl_8045ed4c = 0x8045ed4c;
memset = 0x802eefe0;
SECTIONS {
  .text.w3d_s10_register_properties_801cb170 0x801cb170 : { *(.text.w3d_s10_register_properties_801cb170) }
  .sdata 0x804b051c (NOLOAD) : {
    . = 0x0; lbl_804b051c = .;
    . = 0x4; lbl_804b0520 = .;
    . = 0x8; lbl_804b0524 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
