/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d31g_stage_cache_80078f48)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
lbl_80415b00 = 0x80415b00;
memcpy_802eee50 = 0x802eee50;
w3d_alloc_80212fd4 = 0x80212fd4;
w3d_append_801ef174 = 0x801ef174;
w3d_create_8020b680 = 0x8020b680;
w3d_free_802134fc = 0x802134fc;
w3d_heap_802098d8 = 0x802098d8;
w3d_reserve_801f29d0 = 0x801f29d0;
w3d_stage_add_801d086c = 0x801d086c;
w3d_stage_set_801d0898 = 0x801d0898;
w3d_stages_801d0858 = 0x801d0858;
SECTIONS {
  .text.w3d_d31g_stage_cache_80078f48 0x80078f48 : { *(.text.w3d_d31g_stage_cache_80078f48) }
  .sdata 0x804adde4 (NOLOAD) : {
    . = 0x0; lbl_804adde4 = .;
    . = 0x3a10; lbl_804b17f4 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
