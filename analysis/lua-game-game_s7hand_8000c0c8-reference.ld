/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_auto_8000c0c8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8000B2F8 = 0x8000b2f8;
fn_8000B4C4 = 0x8000b4c4;
fn_80341694 = 0x80341694;
lbl_80369CC4 = 0x80369cc4;
lbl_80369CC8 = 0x80369cc8;
SECTIONS {
  .text.w3d_auto_8000c0c8 0x8000c0c8 : { *(.text.w3d_auto_8000c0c8) }
  .sdata 0x804aa6d8 (NOLOAD) : {
    . = 0x0; lbl_804AA6D8 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
