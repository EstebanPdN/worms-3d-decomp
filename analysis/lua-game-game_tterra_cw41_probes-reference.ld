/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(tterra_cw41_add_80322ce0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_803345bc = 0x803345bc;
fn_803345f0 = 0x803345f0;
fn_8033dcf0 = 0x8033dcf0;
fn_8033de40 = 0x8033de40;
SECTIONS {
  .text.tterra_cw41_add_80322ce0 0x80322ce0 : { *(.text.tterra_cw41_add_80322ce0) }
  .text.tterra_cw41_remove_80322d00 0x80322d00 : { *(.text.tterra_cw41_remove_80322d00) }
  .text.tterra_cw41_init_8033457c 0x8033457c : { *(.text.tterra_cw41_init_8033457c) }
  .text.tterra_cw41_disable_8033459c 0x8033459c : { *(.text.tterra_cw41_disable_8033459c) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
