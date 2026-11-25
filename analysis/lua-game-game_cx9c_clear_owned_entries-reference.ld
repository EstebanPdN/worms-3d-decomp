/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cx9c_clear_owned_entries_80342a7c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cx9c_buffer_release_800152ac = 0x800152ac;
cx9c_entry_finish_8001d1d8 = 0x8001d1d8;
SECTIONS {
  .text.w3d_cx9c_clear_owned_entries_80342a7c 0x80342a7c : { *(.text.w3d_cx9c_clear_owned_entries_80342a7c) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
