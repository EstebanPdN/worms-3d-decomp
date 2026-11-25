/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s8_transplant_800dfd8c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8003a264 = 0x8003a264;
fn_801613f0 = 0x801613f0;
fn_8016239c = 0x8016239c;
SECTIONS {
  .text.s8_transplant_800dfd8c 0x800dfd8c : { *(.text.s8_transplant_800dfd8c) }
  .sdata 0x804b1754 (NOLOAD) : {
    . = 0x0; lbl_804b1754 = .;
    . = 0x4c; lbl_804b17a0 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
