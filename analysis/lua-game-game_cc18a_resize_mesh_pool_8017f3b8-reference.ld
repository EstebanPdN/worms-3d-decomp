/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cc18a_resize_mesh_pool_8017f3b8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__26Cc18aPool_element_80180880 = 0x80180880;
__vd__26Cc18aPool_element_80180880Pv = 0x801fe240;
__vn__26Cc18aPool_element_80180880Ui = 0x801fe220;
fn_8017f52c = 0x8017f52c;
fn_801fe220 = 0x801fe220;
fn_801fe240 = 0x801fe240;
SECTIONS {
  .text.w3d_cc18a_resize_mesh_pool_8017f3b8 0x8017f3b8 : { *(.text.w3d_cc18a_resize_mesh_pool_8017f3b8) }
  .sdata 0x804ab60c (NOLOAD) : {
    . = 0x0; lbl_804ab60c = .;
    . = 0x4; lbl_804ab610 = .;
    . = 0xc; lbl_804ab618 = .;
    . = 0x10; lbl_804ab61c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
