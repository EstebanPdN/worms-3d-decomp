/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_auto_8002726c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_800FC6DC = 0x800fc6dc;
fn_80178C48 = 0x80178c48;
fn_803426B4 = 0x803426b4;
lbl_8036CB60 = 0x8036cb60;
SECTIONS {
  .text.w3d_auto_8002726c 0x8002726c : { *(.text.w3d_auto_8002726c) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
