/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_fn_8006ab48)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_cached_message_id = 0x8015f5a0;
w3d_fn_8006ac40 = 0x8006ac40;
w3d_fn_8006ac90 = 0x8006ac90;
w3d_fn_8006af38 = 0x8006af38;
w3d_fn_801613f0 = 0x801613f0;
w3d_message_post_current = 0x8016239c;
w3d_vtable_8040db38 = 0x8040db38;
SECTIONS {
  .text.w3d_fn_8006ab48 0x8006ab48 : { *(.text.w3d_fn_8006ab48) }
  .text.w3d_fn_8006ae58 0x8006ae58 : { *(.text.w3d_fn_8006ae58) }
  .sdata 0x804ad81c (NOLOAD) : {
    . = 0x0; w3d_message_804ad81c = .;
    . = 0x3f38; w3d_queue_804b1754 = .;
    . = 0x3fd0; w3d_cache_context_804b17ec = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
