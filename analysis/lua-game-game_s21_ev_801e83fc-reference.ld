/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s21_release_801e83fc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801e828c = 0x801e828c;
fn_801e82ec = 0x801e82ec;
fn_801fe1f8 = 0x801fe1f8;
lbl_80417010 = 0x80417010;
SECTIONS {
  .text.w3d_s21_release_801e83fc 0x801e83fc : { *(.text.w3d_s21_release_801e83fc) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
