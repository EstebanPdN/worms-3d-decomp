/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_assign_refs_801f2b04)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801f282c = 0x801f282c;
fn_80210b90 = 0x80210b90;
SECTIONS {
  .text.w3d_assign_refs_801f2b04 0x801f2b04 : { *(.text.w3d_assign_refs_801f2b04) }
  .text.w3d_assign_refs_80210eb4 0x80210eb4 : { *(.text.w3d_assign_refs_80210eb4) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
