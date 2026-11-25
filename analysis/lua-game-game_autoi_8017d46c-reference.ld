/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_auto_8017d46c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
lbl_80456F14 = 0x80456f14;
lbl_804A8DD8 = 0x804a8dd8;
lbl_804A8FD8 = 0x804a8fd8;
lbl_804A9CF8 = 0x804a9cf8;
SECTIONS {
  .text.w3d_auto_8017d46c 0x8017d46c : { *(.text.w3d_auto_8017d46c) }
  .text.w3d_auto_8017d530 0x8017d530 : { *(.text.w3d_auto_8017d530) }
  .text.w3d_auto_8017dca8 0x8017dca8 : { *(.text.w3d_auto_8017dca8) }
  .text.w3d_auto_802cd2e0 0x802cd2e0 : { *(.text.w3d_auto_802cd2e0) }
  .sdata 0x804abce4 (NOLOAD) : {
    . = 0x0; lbl_804ABCE4 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
