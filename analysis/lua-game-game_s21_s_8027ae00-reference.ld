/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s21_state_dispatch_8027ae00)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_80275f18 = 0x80275f18;
fn_80278e38 = 0x80278e38;
fn_8027aa3c = 0x8027aa3c;
SECTIONS {
  .text.w3d_s21_state_dispatch_8027ae00 0x8027ae00 : { *(.text.w3d_s21_state_dispatch_8027ae00) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
