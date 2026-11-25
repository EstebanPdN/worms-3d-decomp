/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cc32b_pop_line_802cbb5c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8020bb2c = 0x8020bb2c;
fn_8020c5c4 = 0x8020c5c4;
fn_802ef2fc = 0x802ef2fc;
fn_80341588 = 0x80341588;
lbl_80473624 = 0x80473624;
lbl_804737a4 = 0x804737a4;
SECTIONS {
  .text.w3d_cc32b_pop_line_802cbb5c 0x802cbb5c : { *(.text.w3d_cc32b_pop_line_802cbb5c) }
  .sdata 0x804abce4 (NOLOAD) : {
    . = 0x0; lbl_804abce4 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
