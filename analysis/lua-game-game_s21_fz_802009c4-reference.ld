/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s21_static_register_value_type_802009c4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_80200af8 = 0x80200af8;
lbl_80200278 = 0x80200278;
lbl_802002fc = 0x802002fc;
lbl_803b2a7c = 0x803b2a7c;
lbl_8045eddc = 0x8045eddc;
lbl_80463308 = 0x80463308;
SECTIONS {
  .text.w3d_s21_static_register_value_type_802009c4 0x802009c4 : { *(.text.w3d_s21_static_register_value_type_802009c4) }
  .sdata 0x804b063c (NOLOAD) : {
    . = 0x0; lbl_804b063c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
