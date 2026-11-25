/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(cxb3_transition_801241d0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801242e0 = 0x801242e0;
fn_801243b0 = 0x801243b0;
fn_80124424 = 0x80124424;
fn_801244d8 = 0x801244d8;
fn_8015f620 = 0x8015f620;
fn_8015fd1c = 0x8015fd1c;
fn_8016293c = 0x8016293c;
SECTIONS {
  .text.cxb3_transition_801241d0 0x801241d0 : { *(.text.cxb3_transition_801241d0) }
  .sdata 0x804af4f0 (NOLOAD) : {
    . = 0x0; lbl_804af4f0 = .;
    . = 0x8; lbl_804af4f8 = .;
    . = 0x10; lbl_804af500 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
