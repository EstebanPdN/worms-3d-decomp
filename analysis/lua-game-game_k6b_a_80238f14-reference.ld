/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_k6b_named_entry_construct_80238f14)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
lbl_8041b080 = 0x8041b080;
lbl_804b06a0 = 0x804b06a0;
w3d_auto_80238d88 = 0x80238d88;
w3d_string_base_init = 0x8020c5c0;
w3d_string_header = 0x80341884;
SECTIONS {
  .text.w3d_k6b_named_entry_construct_80238f14 0x80238f14 : { *(.text.w3d_k6b_named_entry_construct_80238f14) }
  .sdata 0x804af594 (NOLOAD) : {
    . = 0x0; lbl_804af594 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
