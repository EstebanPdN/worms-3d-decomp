/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s9_release_actor_inner_8013e458)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8013f08c = 0x8013f08c;
fn_8013f6b4 = 0x8013f6b4;
fn_8016c7d0 = 0x8016c7d0;
fn_8017fe2c = 0x8017fe2c;
fn_8018d5b8 = 0x8018d5b8;
fn_8034435c = 0x8034435c;
SECTIONS {
  .text.s9_release_actor_inner_8013e458 0x8013e458 : { *(.text.s9_release_actor_inner_8013e458) }
  .text.s9_adjust_disable_8016d3ec 0x8016d3ec : { *(.text.s9_adjust_disable_8016d3ec) }
  .text.s9_invoke_callback_8017f5c8 0x8017f5c8 : { *(.text.s9_invoke_callback_8017f5c8) }
  .text.s9_fill_values_8018d434 0x8018d434 : { *(.text.s9_fill_values_8018d434) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
