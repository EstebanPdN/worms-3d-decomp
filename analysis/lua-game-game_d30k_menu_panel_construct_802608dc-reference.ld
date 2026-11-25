/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d30k_menu_panel_construct_802608dc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__4Text = 0x803426b8;
fn_801628b0 = 0x801628b0;
lbl_8041bbc0 = 0x8041bbc0;
SECTIONS {
  .text.w3d_d30k_menu_panel_construct_802608dc 0x802608dc : { *(.text.w3d_d30k_menu_panel_construct_802608dc) }
  .rodata 0x803cac38 : { *(.rodata) }
  .sdata 0x804aaabc (NOLOAD) : {
    . = 0x0; lbl_804aaabc = .;
    . = 0x1088; lbl_804abb44 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
