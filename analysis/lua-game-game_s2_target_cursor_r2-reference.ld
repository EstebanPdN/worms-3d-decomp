/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_target_cursor_create_80118bf0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_constant_8015fb2c = 0x8015fb2c;
w3d_fn_8004db14 = 0x8004db14;
w3d_fn_8004dc38 = 0x8004dc38;
w3d_fn_8004ddc8 = 0x8004ddc8;
w3d_fn_8004e2a4 = 0x8004e2a4;
w3d_fn_8004e384 = 0x8004e384;
w3d_fn_800fc230 = 0x800fc230;
w3d_fn_8015f65c = 0x8015f65c;
w3d_heap_allocate_entry_a = 0x801fe1d8;
w3d_obj_80410908 = 0x80410908;
w3d_registry_80361260 = 0x80361260;
w3d_registry_unlink_80118bac = 0x80118bac;
w3d_state_register = 0x8020fd04;
w3d_str_8039aa8c = 0x8039aa8c;
SECTIONS {
  .text.w3d_target_cursor_create_80118bf0 0x80118bf0 : { *(.text.w3d_target_cursor_create_80118bf0) }
  .text.w3d_target_cursor_release_80118c68 0x80118c68 : { *(.text.w3d_target_cursor_release_80118c68) }
  .text.w3d_target_cursor_tick_80118edc 0x80118edc : { *(.text.w3d_target_cursor_tick_80118edc) }
  .text.w3d_target_cursor_dispatch_80118f5c 0x80118f5c : { *(.text.w3d_target_cursor_dispatch_80118f5c) }
  .sdata 0x804ad424 (NOLOAD) : {
    . = 0x0; w3d_obj_804ad424 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
