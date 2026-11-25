/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cx12b_movie_shutdown_802e03e0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
callback_80311210 = 0x80311210;
collect_80209968 = 0x80209968;
destroy_801fe1f8 = 0x801fe1f8;
lock_802fdb6c = 0x802fdb6c;
message_803db058 = 0x803db058;
print_802ebfbc = 0x802ebfbc;
quit_802fabc8 = 0x802fabc8;
release_80209920 = 0x80209920;
unlock_802fdb94 = 0x802fdb94;
SECTIONS {
  .text.w3d_cx12b_movie_shutdown_802e03e0 0x802e03e0 : { *(.text.w3d_cx12b_movie_shutdown_802e03e0) }
  .sdata 0x804ab8b4 (NOLOAD) : {
    . = 0x0; heap_804ab8b4 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
