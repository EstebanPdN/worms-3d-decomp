/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d11b_clear_preview_8026d328)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
d11b_preview_light_803cbd18 = 0x803cbd18;
d11b_release_preview_root_8015fd1c = 0x8015fd1c;
SECTIONS {
  .text.d11b_clear_preview_8026d328 0x8026d328 : { *(.text.d11b_clear_preview_8026d328) }
  .sdata 0x804b17ec (NOLOAD) : {
    . = 0x0; d11b_preview_services_804b17ec = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
