/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(terra_only_c6_process_8021bffc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8020b680 = 0x8020b680;
fn_80240b84 = 0x80240b84;
lbl_80418de0 = 0x80418de0;
SECTIONS {
  .text.terra_only_c6_process_8021bffc 0x8021bffc : { *(.text.terra_only_c6_process_8021bffc) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
