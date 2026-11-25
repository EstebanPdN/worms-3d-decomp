/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s19_hide_when_flagged_800a4038)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
s19_visibility_hide_800a3bb4 = 0x800a3bb4;
w3d_auto_80178d1c = 0x80178d1c;
w3d_constructor_native_cast = 0x80342a78;
SECTIONS {
  .text.s19_hide_when_flagged_800a4038 0x800a4038 : { *(.text.s19_hide_when_flagged_800a4038) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
