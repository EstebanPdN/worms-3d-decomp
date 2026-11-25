/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(cc23a_path_vertical_fit_8000519c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8001e11c = 0x8001e11c;
fn_8001e1a0 = 0x8001e1a0;
SECTIONS {
  .text.cc23a_path_vertical_fit_8000519c 0x8000519c : { *(.text.cc23a_path_vertical_fit_8000519c) }
  .sdata 0x804b1758 (NOLOAD) : {
    . = 0x0; lbl_804b1758 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
