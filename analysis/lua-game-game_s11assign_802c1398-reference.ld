/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_auto_802c1398)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8015FD1C = 0x8015fd1c;
lbl_804668D0 = 0x804668d0;
lbl_804668DC = 0x804668dc;
SECTIONS {
  .text.w3d_auto_802c1398 0x802c1398 : { *(.text.w3d_auto_802c1398) }
  .sdata 0x804abb60 (NOLOAD) : {
    . = 0x0; lbl_804ABB60 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
