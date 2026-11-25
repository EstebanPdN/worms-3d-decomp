/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_f1a_begin_record_8003fbe8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8003ffb8 = 0x8003ffb8;
lbl_804273ec = 0x804273ec;
lbl_80427408 = 0x80427408;
SECTIONS {
  .text.w3d_f1a_begin_record_8003fbe8 0x8003fbe8 : { *(.text.w3d_f1a_begin_record_8003fbe8) }
  .sdata 0x804aa950 (NOLOAD) : {
    . = 0x0; lbl_804aa950 = .;
    . = 0x4; lbl_804aa954 = .;
    . = 0x8; lbl_804aa958 = .;
    . = 0xc; lbl_804aa95c = .;
    . = 0x10; lbl_804aa960 = .;
    . = 0x14; lbl_804aa964 = .;
    . = 0x6e40; lbl_804b1790 = .;
    . = 0x6e60; lbl_804b17b0 = .;
    . = 0x6e64; lbl_804b17b4 = .;
    . = 0x6e68; lbl_804b17b8 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
