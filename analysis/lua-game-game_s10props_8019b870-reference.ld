/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s10_register_properties_8019b870)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801e8d9c = 0x801e8d9c;
fn_801efd34 = 0x801efd34;
fn_801efd98 = 0x801efd98;
fn_801efff0 = 0x801efff0;
lbl_803a96b4 = 0x803a96b4;
lbl_803a96c0 = 0x803a96c0;
lbl_803a96c8 = 0x803a96c8;
lbl_803a96d4 = 0x803a96d4;
lbl_8045cd34 = 0x8045cd34;
lbl_8045cd48 = 0x8045cd48;
lbl_8045cd5c = 0x8045cd5c;
lbl_8045cd70 = 0x8045cd70;
lbl_8045ed1c = 0x8045ed1c;
lbl_8045ed34 = 0x8045ed34;
lbl_8045ed94 = 0x8045ed94;
memset = 0x802eefe0;
SECTIONS {
  .text.w3d_s10_register_properties_8019b870 0x8019b870 : { *(.text.w3d_s10_register_properties_8019b870) }
  .sdata 0x804b0300 (NOLOAD) : {
    . = 0x0; lbl_804b0300 = .;
    . = 0x4; lbl_804b0304 = .;
    . = 0x8; lbl_804b0308 = .;
    . = 0xc; lbl_804b030c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
