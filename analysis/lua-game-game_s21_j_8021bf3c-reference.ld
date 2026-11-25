/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s21_expire_entry_8021bf3c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_80165254 = 0x80165254;
fn_8021dd04 = 0x8021dd04;
SECTIONS {
  .text.w3d_s21_expire_entry_8021bf3c 0x8021bf3c : { *(.text.w3d_s21_expire_entry_8021bf3c) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
