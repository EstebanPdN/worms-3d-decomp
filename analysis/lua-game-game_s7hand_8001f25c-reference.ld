/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_auto_8001f25c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_80015588 = 0x80015588;
fn_8001F30C = 0x8001f30c;
fn_8001F4F4 = 0x8001f4f4;
lbl_8036B8B0 = 0x8036b8b0;
SECTIONS {
  .text.w3d_auto_8001f25c 0x8001f25c : { *(.text.w3d_auto_8001f25c) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
