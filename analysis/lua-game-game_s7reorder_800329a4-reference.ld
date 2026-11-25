/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_auto_800329a4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_80032BB0 = 0x80032bb0;
fn_8020B680 = 0x8020b680;
lbl_804138C0 = 0x804138c0;
lbl_804163F8 = 0x804163f8;
SECTIONS {
  .text.w3d_auto_800329a4 0x800329a4 : { *(.text.w3d_auto_800329a4) }
  .sdata 0x804b1788 (NOLOAD) : {
    . = 0x0; lbl_804B1788 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
