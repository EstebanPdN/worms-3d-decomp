/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_auto_800272b0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_80027114 = 0x80027114;
fn_800271EC = 0x800271ec;
fn_80165254 = 0x80165254;
SECTIONS {
  .text.w3d_auto_800272b0 0x800272b0 : { *(.text.w3d_auto_800272b0) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
