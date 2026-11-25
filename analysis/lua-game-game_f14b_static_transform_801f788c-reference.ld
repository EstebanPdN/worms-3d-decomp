/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(f14b_static_transform_801f788c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
lbl_8045e748 = 0x8045e748;
SECTIONS {
  .text.f14b_static_transform_801f788c 0x801f788c : { *(.text.f14b_static_transform_801f788c) }
  .rodata 0x803b17ac : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
