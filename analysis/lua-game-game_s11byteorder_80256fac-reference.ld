/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_auto_80256fac)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801EA0EC = 0x801ea0ec;
fn_8025CA78 = 0x8025ca78;
lbl_8041B9A0 = 0x8041b9a0;
SECTIONS {
  .text.w3d_auto_80256fac 0x80256fac : { *(.text.w3d_auto_80256fac) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
