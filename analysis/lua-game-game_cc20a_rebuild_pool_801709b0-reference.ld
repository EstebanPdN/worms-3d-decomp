/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cc20a_rebuild_pool_801709b0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__26Cc20aPool_element_80172b14 = 0x80172b14;
__vd__26Cc20aPool_element_80172b14Pv = 0x801fe240;
__vn__26Cc20aPool_element_80172b14Ui = 0x801fe220;
fn_80170b18 = 0x80170b18;
fn_801fe220 = 0x801fe220;
fn_801fe240 = 0x801fe240;
SECTIONS {
  .text.w3d_cc20a_rebuild_pool_801709b0 0x801709b0 : { *(.text.w3d_cc20a_rebuild_pool_801709b0) }
  .sdata 0x804b189c (NOLOAD) : {
    . = 0x0; lbl_804b189c = .;
    . = 0x4; lbl_804b18a0 = .;
    . = 0x8; lbl_804b18a4 = .;
    . = 0xa; lbl_804b18a6 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
