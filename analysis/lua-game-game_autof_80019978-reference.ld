/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_auto_80019978)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
lbl_8036AF4C = 0x8036af4c;
lbl_8041D48C = 0x8041d48c;
SECTIONS {
  .text.w3d_auto_80019978 0x80019978 : { *(.text.w3d_auto_80019978) }
  .text.w3d_auto_8001a758 0x8001a758 : { *(.text.w3d_auto_8001a758) }
  .sdata 0x804aa758 (NOLOAD) : {
    . = 0x0; lbl_804AA758 = .;
    . = 0x20; lbl_804AA778 = .;
    . = 0x7010; lbl_804B1768 = .;
    . = 0x7014; lbl_804B176C = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
