/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cc20a_pair_literals_sinit_800789c8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
lbl_80430020 = 0x80430020;
SECTIONS {
  .text.w3d_cc20a_pair_literals_sinit_800789c8 0x800789c8 : { *(.text.w3d_cc20a_pair_literals_sinit_800789c8) }
  .rodata 0x8037ce58 : { *(.rodata) }
  .sdata 0x804aaafc (NOLOAD) : {
    . = 0x0; lbl_804aaafc = .;
    . = 0x2e98; lbl_804ad994 = .;
    . = 0x2e9c; lbl_804ad998 = .;
    . = 0x2ea0; lbl_804ad99c = .;
    . = 0x2ea4; lbl_804ad9a0 = .;
    . = 0x2ea8; lbl_804ad9a4 = .;
    . = 0x2eac; lbl_804ad9a8 = .;
    . = 0x2eb0; lbl_804ad9ac = .;
    . = 0x2eb4; lbl_804ad9b0 = .;
    . = 0x2eb8; lbl_804ad9b4 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
