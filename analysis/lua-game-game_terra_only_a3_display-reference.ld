/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(terra_only_a3_display_800248f8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
display_80343580 = 0x80343580;
format_8036c738 = 0x8036c738;
model_801797b4 = 0x801797b4;
query_800fc6dc = 0x800fc6dc;
set_text_8018c5b0 = 0x8018c5b0;
sprintf = 0x802ec254;
SECTIONS {
  .text.terra_only_a3_display_800248f8 0x800248f8 : { *(.text.terra_only_a3_display_800248f8) }
  .sdata 0x804b1920 (NOLOAD) : {
    . = 0x0; empty_804b1920 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
