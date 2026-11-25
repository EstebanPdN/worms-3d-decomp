/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_auto_80015540)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_800FC6DC = 0x800fc6dc;
SECTIONS {
  .text.w3d_auto_80015540 0x80015540 : { *(.text.w3d_auto_80015540) }
  .sdata 0x804aa6c0 (NOLOAD) : {
    . = 0x0; lbl_804AA6C0 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
