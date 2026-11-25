/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(terra_only_c5_check_801d60cc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801d6000 = 0x801d6000;
fn_801e9db8 = 0x801e9db8;
fn_801ffea8 = 0x801ffea8;
lbl_803af340 = 0x803af340;
lbl_803af394 = 0x803af394;
SECTIONS {
  .text.terra_only_c5_check_801d60cc 0x801d60cc : { *(.text.terra_only_c5_check_801d60cc) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
