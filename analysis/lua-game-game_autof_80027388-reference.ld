/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_auto_80027388)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_800271EC = 0x800271ec;
fn_800272B0 = 0x800272b0;
fn_80165254 = 0x80165254;
fn_80178DF0 = 0x80178df0;
SECTIONS {
  .text.w3d_auto_80027388 0x80027388 : { *(.text.w3d_auto_80027388) }
  .rodata 0x8036cb68 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
