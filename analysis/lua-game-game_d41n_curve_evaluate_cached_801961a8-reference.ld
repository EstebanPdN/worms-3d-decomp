/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d41n_curve_evaluate_cached_801961a8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_80196504 = 0x80196504;
fn_8019661c = 0x8019661c;
fn_801966a0 = 0x801966a0;
fn_801968e8 = 0x801968e8;
fn_801969c4 = 0x801969c4;
fn_80196a54 = 0x80196a54;
SECTIONS {
  .text.w3d_d41n_curve_evaluate_cached_801961a8 0x801961a8 : { *(.text.w3d_d41n_curve_evaluate_cached_801961a8) }
  .rodata 0x803a84a8 : { *(.rodata) }
  .sdata 0x804b18bc (NOLOAD) : {
    . = 0x0; lastSeg_804b18bc = .;
    . = 0x4; flat_804b18c0 = .;
    . = 0xc; key_804b18c8 = .;
    . = 0x10; idx_804b18cc = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
