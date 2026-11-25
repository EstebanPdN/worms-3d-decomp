/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_auto_80018be0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_800153DC = 0x800153dc;
fn_80015434 = 0x80015434;
fn_802E8094 = 0x802e8094;
fn_802E83CC = 0x802e83cc;
lbl_8036A8D0 = 0x8036a8d0;
SECTIONS {
  .text.w3d_auto_80018be0 0x80018be0 : { *(.text.w3d_auto_80018be0) }
  .rodata 0x8036a8d8 : { *(.rodata) }
  .sdata 0x804aa6d8 (NOLOAD) : {
    . = 0x0; lbl_804AA6D8 = .;
    . = 0x6c; lbl_804AA744 = .;
    . = 0x70; lbl_804AA748 = .;
    . = 0x74; lbl_804AA74C = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
