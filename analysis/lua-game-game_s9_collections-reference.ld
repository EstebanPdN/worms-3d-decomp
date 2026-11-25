/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s9_remove_by_key_801625dc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801d0858 = 0x801d0858;
fn_802098fc = 0x802098fc;
lbl_80456f14 = 0x80456f14;
SECTIONS {
  .text.s9_remove_by_key_801625dc 0x801625dc : { *(.text.s9_remove_by_key_801625dc) }
  .text.s9_forward_global_80166fd0 0x80166fd0 : { *(.text.s9_forward_global_80166fd0) }
  .text.s9_lookup_optional_80174074 0x80174074 : { *(.text.s9_lookup_optional_80174074) }
  .text.s9_set_record_bytes_8017df5c 0x8017df5c : { *(.text.s9_set_record_bytes_8017df5c) }
  .text.s9_get_record_bytes_8017df80 0x8017df80 : { *(.text.s9_get_record_bytes_8017df80) }
  .sdata 0x804b00dc (NOLOAD) : {
    . = 0x0; lbl_804b00dc = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
