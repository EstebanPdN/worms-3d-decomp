/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_destroy_8021a540)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8020803c = 0x8020803c;
fn_8021cc18 = 0x8021cc18;
lbl_80419c68 = 0x80419c68;
SECTIONS {
  .text.w3d_destroy_8021a540 0x8021a540 : { *(.text.w3d_destroy_8021a540) }
  .sdata 0x804abac0 (NOLOAD) : {
    . = 0x0; lbl_804abac0 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
