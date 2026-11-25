/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_auto_8003ce0c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_80181640 = 0x80181640;
fn_801817E0 = 0x801817e0;
fn_80343584 = 0x80343584;
lbl_80374458 = 0x80374458;
lbl_8037445C = 0x8037445c;
SECTIONS {
  .text.w3d_auto_8003ce0c 0x8003ce0c : { *(.text.w3d_auto_8003ce0c) }
  .sdata 0x804aa924 (NOLOAD) : {
    . = 0x0; lbl_804AA924 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
