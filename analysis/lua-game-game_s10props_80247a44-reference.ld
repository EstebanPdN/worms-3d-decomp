/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s10_register_properties_80247a44)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801e8d9c = 0x801e8d9c;
fn_801efcd0 = 0x801efcd0;
lbl_803c3e9c = 0x803c3e9c;
lbl_803c3ea8 = 0x803c3ea8;
lbl_8045ed10 = 0x8045ed10;
lbl_80464db0 = 0x80464db0;
lbl_80464dc4 = 0x80464dc4;
memset = 0x802eefe0;
SECTIONS {
  .text.w3d_s10_register_properties_80247a44 0x80247a44 : { *(.text.w3d_s10_register_properties_80247a44) }
  .sdata 0x804b0884 (NOLOAD) : {
    . = 0x0; lbl_804b0884 = .;
    . = 0x4; lbl_804b0888 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
