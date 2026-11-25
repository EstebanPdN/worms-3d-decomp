/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d24l_strip_text_codes_802cc3d0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
memmove = 0x802eeef4;
strchr = 0x802ef198;
strlen = 0x802ef9c0;
SECTIONS {
  .text.d24l_strip_text_codes_802cc3d0 0x802cc3d0 : { *(.text.d24l_strip_text_codes_802cc3d0) }
  .sdata 0x804abce4 (NOLOAD) : {
    . = 0x0; lbl_804abce4 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
