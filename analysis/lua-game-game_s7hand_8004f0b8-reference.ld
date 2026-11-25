/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_auto_8004f0b8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801628B0 = 0x801628b0;
lbl_8040EAA0 = 0x8040eaa0;
SECTIONS {
  .text.w3d_auto_8004f0b8 0x8004f0b8 : { *(.text.w3d_auto_8004f0b8) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
