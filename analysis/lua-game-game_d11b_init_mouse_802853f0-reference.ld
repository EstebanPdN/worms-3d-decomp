/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d11b_init_mouse_802853f0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
d11b_base_type_803617d0 = 0x803617d0;
d11b_create_mouse_80284ca0 = 0x80284ca0;
d11b_init_cached_name_8015f518 = 0x8015f518;
d11b_init_registry_80160038 = 0x80160038;
d11b_mouse_captured_803cf39c = 0x803cf39c;
d11b_mouse_max_804668dc = 0x804668dc;
d11b_mouse_min_804668d0 = 0x804668d0;
d11b_mouse_moved_803cf388 = 0x803cf388;
d11b_mouse_name_803eb320 = 0x803eb320;
d11b_registry_80368788 = 0x80368788;
SECTIONS {
  .text.d11b_init_mouse_802853f0 0x802853f0 : { *(.text.d11b_init_mouse_802853f0) }
  .rodata 0x803cf3b8 : { *(.rodata) }
  .sdata 0x804b0b8c (NOLOAD) : {
    . = 0x0; d11b_moved_name_804b0b8c = .;
    . = 0x8; d11b_captured_name_804b0b94 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
