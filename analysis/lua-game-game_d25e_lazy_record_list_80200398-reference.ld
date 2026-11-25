/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d25e_lazy_record_list_80200398)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__builtin_new = 0x801fe1d8;
__builtin_vec_new = 0x801fe220;
fn_80200460 = 0x80200460;
fn_80200970 = 0x80200970;
SECTIONS {
  .text.w3d_d25e_lazy_record_list_80200398 0x80200398 : { *(.text.w3d_d25e_lazy_record_list_80200398) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
