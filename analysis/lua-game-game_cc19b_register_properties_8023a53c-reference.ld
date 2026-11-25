/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cc19b_register_properties_8023a53c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801e8d9c = 0x801e8d9c;
fn_801ebf38 = 0x801ebf38;
fn_801efd34 = 0x801efd34;
lbl_803bb558 = 0x803bb558;
lbl_803bb580 = 0x803bb580;
lbl_8045ed1c = 0x8045ed1c;
lbl_80464c0c = 0x80464c0c;
memset = 0x802eefe0;
SECTIONS {
  .text.w3d_cc19b_register_properties_8023a53c 0x8023a53c : { *(.text.w3d_cc19b_register_properties_8023a53c) }
  .sdata 0x804b0830 (NOLOAD) : {
    . = 0x0; lbl_804b0830 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
