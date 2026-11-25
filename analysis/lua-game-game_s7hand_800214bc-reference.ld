/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_auto_800214bc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_80131A84 = 0x80131a84;
fn_801613F0 = 0x801613f0;
fn_8016239C = 0x8016239c;
SECTIONS {
  .text.w3d_auto_800214bc 0x800214bc : { *(.text.w3d_auto_800214bc) }
  .sdata 0x804b1754 (NOLOAD) : {
    . = 0x0; lbl_804B1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
