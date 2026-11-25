/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_auto_802cc58c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_802CCCBC = 0x802cccbc;
lbl_804A9D38 = 0x804a9d38;
SECTIONS {
  .text.w3d_auto_802cc58c 0x802cc58c : { *(.text.w3d_auto_802cc58c) }
  .sdata 0x804abce4 (NOLOAD) : {
    . = 0x0; lbl_804ABCE4 = .;
    . = 0x4; lbl_804ABCE8 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
