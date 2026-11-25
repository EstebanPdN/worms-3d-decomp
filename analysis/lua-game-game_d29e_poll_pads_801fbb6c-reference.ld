/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d29e_poll_pads_801fbb6c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8030110c = 0x8030110c;
fn_80301a90 = 0x80301a90;
fn_80301e04 = 0x80301e04;
lbl_8045e824 = 0x8045e824;
SECTIONS {
  .text.w3d_d29e_poll_pads_801fbb6c 0x801fbb6c : { *(.text.w3d_d29e_poll_pads_801fbb6c) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
