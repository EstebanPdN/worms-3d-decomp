/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cx11b_arena_handle_construct_802097ec)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
arenas_804a91f8 = 0x804a91f8;
flags_802097e4 = 0x802097e4;
init_80209160 = 0x80209160;
register_80209bc8 = 0x80209bc8;
registry_80209a70 = 0x80209a70;
SECTIONS {
  .text.w3d_cx11b_arena_handle_construct_802097ec 0x802097ec : { *(.text.w3d_cx11b_arena_handle_construct_802097ec) }
  .sdata 0x804b18f8 (NOLOAD) : {
    . = 0x0; count_804b18f8 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
