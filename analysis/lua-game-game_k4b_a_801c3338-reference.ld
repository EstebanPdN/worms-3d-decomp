/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_k4b_light_construct_801c3338)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
lbl_80414ce0 = 0x80414ce0;
w3d_k4b_named_color_construct_801b4bcc = 0x801b4bcc;
SECTIONS {
  .text.w3d_k4b_light_construct_801c3338 0x801c3338 : { *(.text.w3d_k4b_light_construct_801c3338) }
  .rodata 0x803ac814 : { *(.rodata) }
  .sdata 0x804b05a8 (NOLOAD) : {
    . = 0x0; lbl_804b05a8 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
