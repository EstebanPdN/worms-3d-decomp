/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_k6b_string_from_int_8020bcc0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
lbl_803b3168 = 0x803b3168;
sprintf = 0x802ec254;
w3d_memcpy_802eee50 = 0x802eee50;
w3d_string_allocate = 0x8020bc88;
w3d_string_base_init = 0x8020c5c0;
SECTIONS {
  .text.w3d_k6b_string_from_int_8020bcc0 0x8020bcc0 : { *(.text.w3d_k6b_string_from_int_8020bcc0) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
