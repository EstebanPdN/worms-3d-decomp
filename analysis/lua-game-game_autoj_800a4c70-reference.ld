/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_auto_800a4c70)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_800A4DE4 = 0x800a4de4;
fn_800A82F0 = 0x800a82f0;
fn_800A8314 = 0x800a8314;
fn_800ED070 = 0x800ed070;
fn_800F90E8 = 0x800f90e8;
fn_800FA21C = 0x800fa21c;
fn_801613F0 = 0x801613f0;
fn_8016239C = 0x8016239c;
fn_80164FC8 = 0x80164fc8;
fn_80165254 = 0x80165254;
fn_80181640 = 0x80181640;
fn_80343584 = 0x80343584;
lbl_80380FA4 = 0x80380fa4;
lbl_80380FAC = 0x80380fac;
lbl_80380FB0 = 0x80380fb0;
lbl_80380FB4 = 0x80380fb4;
lbl_80380FBC = 0x80380fbc;
lbl_80380FC0 = 0x80380fc0;
lbl_80380FC4 = 0x80380fc4;
SECTIONS {
  .text.w3d_auto_800a4c70 0x800a4c70 : { *(.text.w3d_auto_800a4c70) }
  .text.w3d_auto_800a4cd0 0x800a4cd0 : { *(.text.w3d_auto_800a4cd0) }
  .text.w3d_auto_800a7bb4 0x800a7bb4 : { *(.text.w3d_auto_800a7bb4) }
  .text.w3d_auto_800a7c24 0x800a7c24 : { *(.text.w3d_auto_800a7c24) }
  .text.w3d_auto_800e96a0 0x800e96a0 : { *(.text.w3d_auto_800e96a0) }
  .sdata 0x804b1754 (NOLOAD) : {
    . = 0x0; lbl_804B1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
