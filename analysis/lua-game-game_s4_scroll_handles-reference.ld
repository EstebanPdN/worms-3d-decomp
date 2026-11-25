/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s4_scroll_handle_destroy)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_actor_member_delete_backend = 0x801fe1f8;
w3d_scroll_remove_80287c88 = 0x80287c88;
SECTIONS {
  .text.w3d_s4_scroll_handle_destroy 0x80293528 : { *(.text.w3d_s4_scroll_handle_destroy) }
  .text.w3d_s4_scroll_set_child 0x80294398 : { *(.text.w3d_s4_scroll_set_child) }
  .text.w3d_s4_scroll_bind_to 0x802943cc : { *(.text.w3d_s4_scroll_bind_to) }
  .text.w3d_s4_scroll_refresh 0x8029459c : { *(.text.w3d_s4_scroll_refresh) }
  .sdata 0x804abbc8 (NOLOAD) : {
    . = 0x0; w3d_global_804abbc8 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
