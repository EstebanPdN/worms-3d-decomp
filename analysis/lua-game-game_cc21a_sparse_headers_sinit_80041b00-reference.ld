/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(cc21a_sparse_headers_sinit_80041b00)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cc21a_fn_8003f16c = 0x8003f16c;
cc21a_fn_801629f8 = 0x801629f8;
cc21a_lbl_80360030 = 0x80360030;
cc21a_lbl_803618f0 = 0x803618f0;
cc21a_lbl_803e7a24 = 0x803e7a24;
cc21a_lbl_804273ec = 0x804273ec;
cc21a_lbl_804273fc = 0x804273fc;
SECTIONS {
  .text.cc21a_sparse_headers_sinit_80041b00 0x80041b00 : { *(.text.cc21a_sparse_headers_sinit_80041b00) }
  .sdata 0x804aa94c (NOLOAD) : {
    . = 0x0; cc21a_lbl_804aa94c = .;
    . = 0x2870; cc21a_lbl_804ad1bc = .;
    . = 0x2874; cc21a_lbl_804ad1c0 = .;
    . = 0x2878; cc21a_lbl_804ad1c4 = .;
    . = 0x287c; cc21a_lbl_804ad1c8 = .;
    . = 0x2880; cc21a_lbl_804ad1cc = .;
    . = 0x2884; cc21a_lbl_804ad1d0 = .;
    . = 0x2888; cc21a_lbl_804ad1d4 = .;
    . = 0x288c; cc21a_lbl_804ad1d8 = .;
    . = 0x2890; cc21a_lbl_804ad1dc = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
