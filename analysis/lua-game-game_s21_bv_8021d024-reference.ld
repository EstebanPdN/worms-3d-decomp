/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s21_register_descriptor_8021d024)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_80200a70 = 0x80200a70;
lbl_803b42e4 = 0x803b42e4;
lbl_8040e528 = 0x8040e528;
lbl_804641ec = 0x804641ec;
lbl_804641f0 = 0x804641f0;
SECTIONS {
  .text.w3d_s21_register_descriptor_8021d024 0x8021d024 : { *(.text.w3d_s21_register_descriptor_8021d024) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
