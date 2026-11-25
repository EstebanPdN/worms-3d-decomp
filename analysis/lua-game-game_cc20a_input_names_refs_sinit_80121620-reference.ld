/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cc20a_input_names_refs_sinit_80121620)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8015f518 = 0x8015f518;
lbl_8039b714 = 0x8039b714;
lbl_8039b728 = 0x8039b728;
lbl_8039b73c = 0x8039b73c;
lbl_8039b750 = 0x8039b750;
lbl_8039b760 = 0x8039b760;
lbl_8039b77c = 0x8039b77c;
lbl_8039b78c = 0x8039b78c;
lbl_8039b79c = 0x8039b79c;
lbl_8039b7a0 = 0x8039b7a0;
lbl_8044f2b4 = 0x8044f2b4;
SECTIONS {
  .text.w3d_cc20a_input_names_refs_sinit_80121620 0x80121620 : { *(.text.w3d_cc20a_input_names_refs_sinit_80121620) }
  .sdata 0x804ab034 (NOLOAD) : {
    . = 0x0; lbl_804ab034 = .;
    . = 0x445c; lbl_804af490 = .;
    . = 0x4460; lbl_804af494 = .;
    . = 0x4464; lbl_804af498 = .;
    . = 0x4468; lbl_804af49c = .;
    . = 0x446c; lbl_804af4a0 = .;
    . = 0x4470; lbl_804af4a4 = .;
    . = 0x4474; lbl_804af4a8 = .;
    . = 0x4478; lbl_804af4ac = .;
    . = 0x447c; lbl_804af4b0 = .;
    . = 0x4480; lbl_804af4b4 = .;
    . = 0x4488; lbl_804af4bc = .;
    . = 0x4490; lbl_804af4c4 = .;
    . = 0x4498; lbl_804af4cc = .;
    . = 0x44a0; lbl_804af4d4 = .;
    . = 0x44a8; lbl_804af4dc = .;
    . = 0x44b0; lbl_804af4e4 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
