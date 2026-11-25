/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s21_install_hooks_80217f8c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_80217c6c = 0x80217c6c;
fn_80217cd4 = 0x80217cd4;
fn_80217dac = 0x80217dac;
lbl_80400768 = 0x80400768;
SECTIONS {
  .text.w3d_s21_install_hooks_80217f8c 0x80217f8c : { *(.text.w3d_s21_install_hooks_80217f8c) }
  .sdata 0x804aba90 (NOLOAD) : {
    . = 0x0; lbl_804aba90 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
