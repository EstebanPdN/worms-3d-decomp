/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(cxc2_singleton_8020b884)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801fe1d8 = 0x801fe1d8;
fn_80218284 = 0x80218284;
SECTIONS {
  .text.cxc2_singleton_8020b884 0x8020b884 : { *(.text.cxc2_singleton_8020b884) }
  .sdata 0x804abaa4 (NOLOAD) : {
    . = 0x0; lbl_804abaa4 = .;
    . = 0x4bf4; lbl_804b0698 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
