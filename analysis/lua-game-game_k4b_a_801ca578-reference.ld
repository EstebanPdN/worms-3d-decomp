/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_k4b_named_refs_construct_801ca578)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
lbl_804162a8 = 0x804162a8;
w3d_k4b_named_construct_801c90c0 = 0x801c90c0;
SECTIONS {
  .text.w3d_k4b_named_refs_construct_801ca578 0x801ca578 : { *(.text.w3d_k4b_named_refs_construct_801ca578) }
  .sdata 0x804b05a8 (NOLOAD) : {
    . = 0x0; lbl_804b05a8 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
