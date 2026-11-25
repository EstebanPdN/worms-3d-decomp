/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s21_set_buffer_801df57c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801fe220 = 0x801fe220;
fn_801fe240 = 0x801fe240;
fn_802eee50 = 0x802eee50;
SECTIONS {
  .text.w3d_s21_set_buffer_801df57c 0x801df57c : { *(.text.w3d_s21_set_buffer_801df57c) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
