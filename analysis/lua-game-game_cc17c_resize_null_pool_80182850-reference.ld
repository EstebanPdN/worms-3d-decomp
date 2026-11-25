/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cc17c_resize_null_pool_80182850)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__25Cc17cPoolElement_80182de0 = 0x80182de0;
__vd__25Cc17cPoolElement_80182de0Pv = 0x801fe240;
__vn__25Cc17cPoolElement_80182de0Ui = 0x801fe220;
fn_801829c4 = 0x801829c4;
fn_801fe220 = 0x801fe220;
fn_801fe240 = 0x801fe240;
SECTIONS {
  .text.w3d_cc17c_resize_null_pool_80182850 0x80182850 : { *(.text.w3d_cc17c_resize_null_pool_80182850) }
  .sdata 0x804ab634 (NOLOAD) : {
    . = 0x0; lbl_804ab634 = .;
    . = 0x4; lbl_804ab638 = .;
    . = 0xc; lbl_804ab640 = .;
    . = 0x10; lbl_804ab644 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
