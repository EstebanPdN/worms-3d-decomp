/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(cc21a_sparse_headers_sinit_800c1468)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cc21a_fn_800bfee0 = 0x800bfee0;
cc21a_fn_801629f8 = 0x801629f8;
cc21a_lbl_80360960 = 0x80360960;
cc21a_lbl_803618f0 = 0x803618f0;
cc21a_lbl_803e7f80 = 0x803e7f80;
cc21a_lbl_8043c384 = 0x8043c384;
cc21a_lbl_8043c394 = 0x8043c394;
cc21a_lbl_8043c3a0 = 0x8043c3a0;
SECTIONS {
  .text.cc21a_sparse_headers_sinit_800c1468 0x800c1468 : { *(.text.cc21a_sparse_headers_sinit_800c1468) }
  .sdata 0x804aada4 (NOLOAD) : {
    . = 0x0; cc21a_lbl_804aada4 = .;
    . = 0x3874; cc21a_lbl_804ae618 = .;
    . = 0x3878; cc21a_lbl_804ae61c = .;
    . = 0x387c; cc21a_lbl_804ae620 = .;
    . = 0x3880; cc21a_lbl_804ae624 = .;
    . = 0x3884; cc21a_lbl_804ae628 = .;
    . = 0x3888; cc21a_lbl_804ae62c = .;
    . = 0x388c; cc21a_lbl_804ae630 = .;
    . = 0x3890; cc21a_lbl_804ae634 = .;
    . = 0x3894; cc21a_lbl_804ae638 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
