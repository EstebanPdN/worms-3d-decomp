/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_f2a_update_phase_80028e10)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_80178c48 = 0x80178c48;
fn_80178df0 = 0x80178df0;
fn_802e88ac = 0x802e88ac;
lbl_8036cec8 = 0x8036cec8;
lbl_8036cecc = 0x8036cecc;
lbl_8036ced0 = 0x8036ced0;
lbl_8036ced4 = 0x8036ced4;
lbl_8036ced8 = 0x8036ced8;
SECTIONS {
  .text.w3d_f2a_update_phase_80028e10 0x80028e10 : { *(.text.w3d_f2a_update_phase_80028e10) }
  .rodata 0x8036ceb8 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
