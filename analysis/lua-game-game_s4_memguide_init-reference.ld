/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s4_memguide_initialize)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
memset = 0x802eefe0;
w3d_auto_802abfdc = 0x802abfdc;
w3d_card_guide_step = 0x802c501c;
w3d_fn_802ad924 = 0x802ad924;
SECTIONS {
  .text.w3d_s4_memguide_initialize 0x802ab990 : { *(.text.w3d_s4_memguide_initialize) }
  .text.w3d_s4_memguide_probe_step 0x802abcdc : { *(.text.w3d_s4_memguide_probe_step) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
