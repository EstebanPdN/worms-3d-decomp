/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_auto_8026857c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_80173DF0 = 0x80173df0;
fn_8026710C = 0x8026710c;
fn_8034357C = 0x8034357c;
SECTIONS {
  .text.w3d_auto_8026857c 0x8026857c : { *(.text.w3d_auto_8026857c) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
