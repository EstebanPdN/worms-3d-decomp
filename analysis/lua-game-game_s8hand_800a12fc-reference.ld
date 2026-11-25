/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s8_mesh_start_800a12fc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_800a14c4 = 0x800a14c4;
fn_80181640 = 0x80181640;
fn_801817e0 = 0x801817e0;
fn_80343584 = 0x80343584;
lbl_80380900 = 0x80380900;
lbl_80380904 = 0x80380904;
SECTIONS {
  .text.s8_mesh_start_800a12fc 0x800a12fc : { *(.text.s8_mesh_start_800a12fc) }
  .sdata 0x804aac14 (NOLOAD) : {
    . = 0x0; lbl_804aac14 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
