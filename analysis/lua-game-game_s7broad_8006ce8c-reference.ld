/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_auto_8006ce8c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_800FC230 = 0x800fc230;
lbl_8037C044 = 0x8037c044;
SECTIONS {
  .text.w3d_auto_8006ce8c 0x8006ce8c : { *(.text.w3d_auto_8006ce8c) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
