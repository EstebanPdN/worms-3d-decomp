/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s9_resize_pool_801743b4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__24s9_pool_element_80174b38 = 0x80174b38;
__24s9_pool_element_80185110 = 0x80185110;
__24s9_pool_element_80188a68 = 0x80188a68;
__vd__24s9_pool_element_80174b38Pv = 0x801fe240;
__vd__24s9_pool_element_80185110Pv = 0x801fe240;
__vd__24s9_pool_element_80188a68Pv = 0x801fe240;
__vn__24s9_pool_element_80174b38Ui = 0x801fe220;
__vn__24s9_pool_element_80185110Ui = 0x801fe220;
__vn__24s9_pool_element_80188a68Ui = 0x801fe220;
fn_80174528 = 0x80174528;
fn_80183ebc = 0x80183ebc;
fn_80187754 = 0x80187754;
fn_801fe220 = 0x801fe220;
fn_801fe240 = 0x801fe240;
SECTIONS {
  .text.s9_resize_pool_801743b4 0x801743b4 : { *(.text.s9_resize_pool_801743b4) }
  .text.s9_resize_pool_80183d48 0x80183d48 : { *(.text.s9_resize_pool_80183d48) }
  .text.s9_resize_pool_801875e0 0x801875e0 : { *(.text.s9_resize_pool_801875e0) }
  .sdata 0x804ab588 (NOLOAD) : {
    . = 0x0; lbl_804ab588 = .;
    . = 0x4; lbl_804ab58c = .;
    . = 0x8; lbl_804ab590 = .;
    . = 0xc; lbl_804ab594 = .;
    . = 0xd0; lbl_804ab658 = .;
    . = 0xd4; lbl_804ab65c = .;
    . = 0xdc; lbl_804ab664 = .;
    . = 0xe0; lbl_804ab668 = .;
    . = 0xf8; lbl_804ab680 = .;
    . = 0xfc; lbl_804ab684 = .;
    . = 0x104; lbl_804ab68c = .;
    . = 0x108; lbl_804ab690 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
