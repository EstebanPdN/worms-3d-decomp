/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s9_permute_801680b4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_80168200 = 0x80168200;
SECTIONS {
  .text.s9_permute_801680b4 0x801680b4 : { *(.text.s9_permute_801680b4) }
  .sdata 0x804ab4fc (NOLOAD) : {
    . = 0x0; lbl_804AB4FC = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
