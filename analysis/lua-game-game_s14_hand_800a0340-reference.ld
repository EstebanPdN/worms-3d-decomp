/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s14_mesh_tick_typed_800a0340)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_800a08b0 = 0x800a08b0;
fn_800a0e2c = 0x800a0e2c;
fn_800a12c0 = 0x800a12c0;
fn_800a12fc = 0x800a12fc;
fn_800a14c4 = 0x800a14c4;
fn_800a14f4 = 0x800a14f4;
fn_800a1524 = 0x800a1524;
fn_800fc6dc = 0x800fc6dc;
fn_80165254 = 0x80165254;
fn_80178c48 = 0x80178c48;
fn_80181640 = 0x80181640;
fn_80181ccc = 0x80181ccc;
fn_80343584 = 0x80343584;
lbl_80380864 = 0x80380864;
lbl_80380868 = 0x80380868;
SECTIONS {
  .text.s14_mesh_tick_typed_800a0340 0x800a0340 : { *(.text.s14_mesh_tick_typed_800a0340) }
  .sdata 0x804aac18 (NOLOAD) : {
    . = 0x0; lbl_804aac18 = .;
    . = 0x22c; lbl_804aae44 = .;
    . = 0x6b70; lbl_804b1788 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
