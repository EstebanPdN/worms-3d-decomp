/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_auto_801fdf60)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8016E57C = 0x8016e57c;
fn_8016E5FC = 0x8016e5fc;
fn_8016E6FC = 0x8016e6fc;
fn_8035A3A8 = 0x8035a3a8;
SECTIONS {
  .text.w3d_auto_801fdf60 0x801fdf60 : { *(.text.w3d_auto_801fdf60) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
