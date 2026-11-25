/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d24k_remove_registered_80210120)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_80210dd8 = 0x80210dd8;
fn_8035d164 = 0x8035d164;
lbl_80463be0 = 0x80463be0;
SECTIONS {
  .text.w3d_d24k_remove_registered_80210120 0x80210120 : { *(.text.w3d_d24k_remove_registered_80210120) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
