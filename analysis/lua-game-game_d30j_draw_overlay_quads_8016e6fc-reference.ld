/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d30j_draw_overlay_quads_8016e6fc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cc45a_swap_8016eed0 = 0x8016eed0;
fn_8016e1c0 = 0x8016e1c0;
fn_80302b60 = 0x80302b60;
fn_80302ec4 = 0x80302ec4;
fn_80306cd0 = 0x80306cd0;
fn_80307558 = 0x80307558;
fn_80307590 = 0x80307590;
fn_80308be8 = 0x80308be8;
fn_80308fc0 = 0x80308fc0;
fn_8030990c = 0x8030990c;
fn_8030af88 = 0x8030af88;
fn_8030b3dc = 0x8030b3dc;
fn_8030b4ac = 0x8030b4ac;
fn_8030b648 = 0x8030b648;
fn_8030b9b8 = 0x8030b9b8;
fn_8030ba0c = 0x8030ba0c;
fn_8030ba38 = 0x8030ba38;
fn_8030ba64 = 0x8030ba64;
fn_8030ba98 = 0x8030ba98;
fn_8030bec4 = 0x8030bec4;
fn_8030bff4 = 0x8030bff4;
fn_8030c094 = 0x8030c094;
SECTIONS {
  .text.d30j_draw_overlay_quads_8016e6fc 0x8016e6fc : { *(.text.d30j_draw_overlay_quads_8016e6fc) }
  .rodata 0x803a63bc : { *(.rodata) }
  .sdata 0x804b1884 (NOLOAD) : {
    . = 0x0; lbl_804b1884 = .;
    . = 0x4; lbl_804b1888 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
