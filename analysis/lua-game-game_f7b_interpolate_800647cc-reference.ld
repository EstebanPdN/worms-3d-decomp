/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(f7b_interpolate_800647cc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
get_80178df0 = 0x80178df0;
get_80178ec4 = 0x80178ec4;
set_800649e8 = 0x800649e8;
update_80064198 = 0x80064198;
zero_80379db4 = 0x80379db4;
SECTIONS {
  .text.f7b_interpolate_800647cc 0x800647cc : { *(.text.f7b_interpolate_800647cc) }
  .rodata 0x80379db0 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
