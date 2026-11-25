/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_auto_801fe9cc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8020D8F8 = 0x8020d8f8;
fn_802ED89C = 0x802ed89c;
SECTIONS {
  .text.w3d_auto_801fe9cc 0x801fe9cc : { *(.text.w3d_auto_801fe9cc) }
  .text.w3d_auto_801fea2c 0x801fea2c : { *(.text.w3d_auto_801fea2c) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
