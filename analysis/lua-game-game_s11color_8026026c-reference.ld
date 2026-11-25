/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_auto_8026026c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_80173DF0 = 0x80173df0;
fn_8018D35C = 0x8018d35c;
fn_80260144 = 0x80260144;
fn_8034357C = 0x8034357c;
fn_80343580 = 0x80343580;
SECTIONS {
  .text.w3d_auto_8026026c 0x8026026c : { *(.text.w3d_auto_8026026c) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
