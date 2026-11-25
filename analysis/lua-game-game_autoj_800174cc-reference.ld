/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_auto_800174cc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_80008C44 = 0x80008c44;
fn_80009984 = 0x80009984;
fn_80181640 = 0x80181640;
fn_80343584 = 0x80343584;
lbl_8037446C = 0x8037446c;
lbl_80374470 = 0x80374470;
lbl_80374474 = 0x80374474;
lbl_80374478 = 0x80374478;
lbl_8037447C = 0x8037447c;
lbl_80374480 = 0x80374480;
lbl_80380908 = 0x80380908;
lbl_8038090C = 0x8038090c;
lbl_80380910 = 0x80380910;
lbl_80380914 = 0x80380914;
lbl_80380918 = 0x80380918;
lbl_8038091C = 0x8038091c;
lbl_80380920 = 0x80380920;
lbl_80380924 = 0x80380924;
lbl_80380928 = 0x80380928;
SECTIONS {
  .text.w3d_auto_800174cc 0x800174cc : { *(.text.w3d_auto_800174cc) }
  .text.w3d_auto_8003ce84 0x8003ce84 : { *(.text.w3d_auto_8003ce84) }
  .text.w3d_auto_8003cef0 0x8003cef0 : { *(.text.w3d_auto_8003cef0) }
  .text.w3d_auto_800a1380 0x800a1380 : { *(.text.w3d_auto_800a1380) }
  .text.w3d_auto_800a13ec 0x800a13ec : { *(.text.w3d_auto_800a13ec) }
  .text.w3d_auto_800a1458 0x800a1458 : { *(.text.w3d_auto_800a1458) }
  .sdata 0x804aa92c (NOLOAD) : {
    . = 0x0; lbl_804AA92C = .;
    . = 0x4; lbl_804AA930 = .;
    . = 0x2f0; lbl_804AAC1C = .;
    . = 0x2f4; lbl_804AAC20 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
