/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cx11b_string_substring_construct_8020bbec)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
allocate_8020bc88 = 0x8020bc88;
base_8020c5c0 = 0x8020c5c0;
copy_802eee50 = 0x802eee50;
SECTIONS {
  .text.w3d_cx11b_string_substring_construct_8020bbec 0x8020bbec : { *(.text.w3d_cx11b_string_substring_construct_8020bbec) }
  .sdata 0x804aba1c (NOLOAD) : {
    . = 0x0; empty_804aba1c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
