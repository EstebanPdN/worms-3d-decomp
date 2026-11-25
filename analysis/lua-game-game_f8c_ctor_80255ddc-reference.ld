/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(f8c_ctor_80255ddc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8020c5c0 = 0x8020c5c0;
fn_80251f40 = 0x80251f40;
fn_80341884 = 0x80341884;
lbl_803c8574 = 0x803c8574;
lbl_8041b9f0 = 0x8041b9f0;
lbl_804b06a0 = 0x804b06a0;
SECTIONS {
  .text.f8c_ctor_80255ddc 0x80255ddc : { *(.text.f8c_ctor_80255ddc) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
