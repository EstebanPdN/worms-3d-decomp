/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_auto_80038894)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801628B0 = 0x801628b0;
fn_803426B8 = 0x803426b8;
lbl_8040E690 = 0x8040e690;
SECTIONS {
  .text.w3d_auto_80038894 0x80038894 : { *(.text.w3d_auto_80038894) }
  .sdata 0x804aa900 (NOLOAD) : {
    . = 0x0; lbl_804AA900 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
