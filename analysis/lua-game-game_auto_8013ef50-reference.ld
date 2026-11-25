/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_auto_8013ef50)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_800E5C10 = 0x800e5c10;
fn_800FC6DC = 0x800fc6dc;
fn_80178C48 = 0x80178c48;
fn_803426B4 = 0x803426b4;
SECTIONS {
  .text.w3d_auto_8013ef50 0x8013ef50 : { *(.text.w3d_auto_8013ef50) }
  .text.w3d_auto_8013f260 0x8013f260 : { *(.text.w3d_auto_8013f260) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
