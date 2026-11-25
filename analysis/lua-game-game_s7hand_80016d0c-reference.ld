/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_auto_80016d0c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_80016BEC = 0x80016bec;
SECTIONS {
  .text.w3d_auto_80016d0c 0x80016d0c : { *(.text.w3d_auto_80016d0c) }
  .sdata 0x804aa6d8 (NOLOAD) : {
    . = 0x0; lbl_804AA6D8 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
