/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d30j_init_texture_object_80168744)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8016c4f4 = 0x8016c4f4;
fn_802fa988 = 0x802fa988;
fn_80309a64 = 0x80309a64;
fn_80309c88 = 0x80309c88;
fn_80309ed4 = 0x80309ed4;
s9_forward_global_80166fd0 = 0x80166fd0;
SECTIONS {
  .text.d30j_init_texture_object_80168744 0x80168744 : { *(.text.d30j_init_texture_object_80168744) }
  .sdata 0x804b1884 (NOLOAD) : {
    . = 0x0; lbl_804b1884 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
