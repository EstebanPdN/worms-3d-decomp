/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s20_construct_counted_80174b38)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8017990c = 0x8017990c;
fn_801799d4 = 0x801799d4;
lbl_80412180 = 0x80412180;
SECTIONS {
  .text.w3d_s20_construct_counted_80174b38 0x80174b38 : { *(.text.w3d_s20_construct_counted_80174b38) }
  .text.w3d_s20_destruct_counted_80174b80 0x80174b80 : { *(.text.w3d_s20_destruct_counted_80174b80) }
  .sdata 0x804ab5a0 (NOLOAD) : {
    . = 0x0; lbl_804ab5a0 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
