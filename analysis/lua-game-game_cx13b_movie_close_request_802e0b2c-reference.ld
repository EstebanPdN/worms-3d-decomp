/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cx13b_movie_close_request_802e0b2c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
close_802f5320 = 0x802f5320;
free_80209920 = 0x80209920;
message_803db278 = 0x803db278;
print_802ebfbc = 0x802ebfbc;
reset_80209968 = 0x80209968;
SECTIONS {
  .text.w3d_cx13b_movie_close_request_802e0b2c 0x802e0b2c : { *(.text.w3d_cx13b_movie_close_request_802e0b2c) }
  .sdata 0x804ab8b4 (NOLOAD) : {
    . = 0x0; heap_804ab8b4 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
