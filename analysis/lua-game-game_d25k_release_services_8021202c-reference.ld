/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d25k_release_services_8021202c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
clear_8035c81c = 0x8035c81c;
next_bucket_8035c988 = 0x8035c988;
SECTIONS {
  .text.w3d_d25k_release_services_8021202c 0x8021202c : { *(.text.w3d_d25k_release_services_8021202c) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
