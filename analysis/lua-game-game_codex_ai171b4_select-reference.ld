/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(codex_ai171b4_select)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_80006360 = 0x80006360;
fn_80007514 = 0x80007514;
fn_8001523c = 0x8001523c;
lbl_8036a730 = 0x8036a730;
lbl_8040d8b0 = 0x8040d8b0;
lbl_8040d8e8 = 0x8040d8e8;
SECTIONS {
  .text.codex_ai171b4_select 0x800171b4 : { *(.text.codex_ai171b4_select) }
  .sdata 0x804aa594 (NOLOAD) : {
    . = 0x0; lbl_804aa594 = .;
    . = 0x1bc; lbl_804aa750 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
