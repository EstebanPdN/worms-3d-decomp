/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(bind_position_array_skinned_80169094)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
DCFlushRange = 0x802fa988;
GXSetArray = 0x80307d88;
_S_oom_malloc__Q24_STLt14__malloc_alloc1i0Ui = 0x803413d8;
f13b_skin_801a1250 = 0x801a1250;
f8c_skin_801a1460 = 0x801a1460;
free = 0x802134fc;
malloc = 0x80212fd4;
skin_type_80363654 = 0x80363654;
w3d_auto_8016805c = 0x8016805c;
w3d_cc17b_temp_alloc_8016a21c = 0x8016a21c;
SECTIONS {
  .text.bind_position_array_skinned_80169094 0x80169094 : { *(.text.bind_position_array_skinned_80169094) }
  .sdata 0x804b1884 (NOLOAD) : {
    . = 0x0; global_804b1884 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
