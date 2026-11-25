/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s9_beam_80179428)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8017892C = 0x8017892c;
fn_8020B680 = 0x8020b680;
lbl_804124A0 = 0x804124a0;
lbl_80413068 = 0x80413068;
lbl_80413BE8 = 0x80413be8;
SECTIONS {
  .text.s9_beam_80179428 0x80179428 : { *(.text.s9_beam_80179428) }
  .sdata 0x804ab5cc (NOLOAD) : {
    . = 0x0; lbl_804AB5CC = .;
    . = 0x4b8c; lbl_804B0158 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
