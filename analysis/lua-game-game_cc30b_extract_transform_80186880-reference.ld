/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cc30b_extract_transform_80186880)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801a3eb0 = 0x801a3eb0;
fn_801f6448 = 0x801f6448;
fn_801f740c = 0x801f740c;
fn_80343740 = 0x80343740;
SECTIONS {
  .text.w3d_cc30b_extract_transform_80186880 0x80186880 : { *(.text.w3d_cc30b_extract_transform_80186880) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
