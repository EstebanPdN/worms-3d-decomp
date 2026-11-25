/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cx9a_selection_create_append_800ba4c4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
pool_allocate_802098d8 = 0x802098d8;
selection_construct_800b912c = 0x800b912c;
selection_initialize_800b923c = 0x800b923c;
selection_key_800b4d98 = 0x800b4d98;
selection_set_key_800b9240 = 0x800b9240;
storage_allocate_80212fd4 = 0x80212fd4;
storage_copy_802eee50 = 0x802eee50;
storage_release_802134fc = 0x802134fc;
SECTIONS {
  .text.w3d_cx9a_selection_create_append_800ba4c4 0x800ba4c4 : { *(.text.w3d_cx9a_selection_create_append_800ba4c4) }
  .sdata 0x804adde4 (NOLOAD) : {
    . = 0x0; selection_pool_804adde4 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
