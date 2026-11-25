/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(cc21a_relay_sparse_headers_800c590c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cc21a_fn_800c4ec8 = 0x800c4ec8;
cc21a_fn_801629f8 = 0x801629f8;
cc21a_lbl_80360a80 = 0x80360a80;
cc21a_lbl_803618f0 = 0x803618f0;
cc21a_lbl_803e8028 = 0x803e8028;
cc21a_lbl_8043e438 = 0x8043e438;
cc21a_lbl_8043e448 = 0x8043e448;
SECTIONS {
  .text.cc21a_relay_sparse_headers_800c590c 0x800c590c : { *(.text.cc21a_relay_sparse_headers_800c590c) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
