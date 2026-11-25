/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s8_initialize_registry_800cb040)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_800C84A0 = 0x800c84a0;
fn_8015F518 = 0x8015f518;
fn_80160038 = 0x80160038;
lbl_80360B40 = 0x80360b40;
lbl_803617D0 = 0x803617d0;
lbl_80387CBC = 0x80387cbc;
lbl_803E8098 = 0x803e8098;
lbl_8043EDA4 = 0x8043eda4;
SECTIONS {
  .text.s8_initialize_registry_800cb040 0x800cb040 : { *(.text.s8_initialize_registry_800cb040) }
  .sdata 0x804ae80c (NOLOAD) : {
    . = 0x0; lbl_804AE80C = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
