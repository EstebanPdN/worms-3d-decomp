/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d15e_descriptor_cache_801e88b0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8020b574 = 0x8020b574;
lbl_8040c990 = 0x8040c990;
lbl_8045e048 = 0x8045e048;
memset = 0x802eefe0;
SECTIONS {
  .text.w3d_d15e_descriptor_cache_801e88b0 0x801e88b0 : { *(.text.w3d_d15e_descriptor_cache_801e88b0) }
  .sdata 0x804ac804 (NOLOAD) : {
    . = 0x0; lbl_804ac804 = .;
    . = 0x3d74; lbl_804b0578 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
