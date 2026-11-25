/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d26k_initialise_class_80210370)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
announce_8021020c = 0x8021020c;
name_801ffea8 = 0x801ffea8;
size_80200050 = 0x80200050;
text_803b356c = 0x803b356c;
trace_80347324 = 0x80347324;
SECTIONS {
  .text.w3d_d26k_initialise_class_80210370 0x80210370 : { *(.text.w3d_d26k_initialise_class_80210370) }
  .sdata 0x804b0640 (NOLOAD) : {
    . = 0x0; global_804b0640 = .;
    . = 0x12c4; global_804b1904 = .;
    . = 0x12c8; global_804b1908 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
