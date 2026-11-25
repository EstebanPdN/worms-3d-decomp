/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cc17c_resize_pool_8018a678)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__25Cc17cPoolElement_8018bd30 = 0x8018bd30;
__vd__25Cc17cPoolElement_8018bd30Pv = 0x801fe240;
__vn__25Cc17cPoolElement_8018bd30Ui = 0x801fe220;
fn_8018a7ec = 0x8018a7ec;
fn_801fe220 = 0x801fe220;
fn_801fe240 = 0x801fe240;
SECTIONS {
  .text.w3d_cc17c_resize_pool_8018a678 0x8018a678 : { *(.text.w3d_cc17c_resize_pool_8018a678) }
  .sdata 0x804b18ac (NOLOAD) : {
    . = 0x0; lbl_804b18ac = .;
    . = 0x4; lbl_804b18b0 = .;
    . = 0x8; lbl_804b18b4 = .;
    . = 0xc; lbl_804b18b8 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
