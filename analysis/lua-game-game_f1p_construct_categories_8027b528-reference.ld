/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_construct_categories_8027b528)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801628b0 = 0x801628b0;
vt_8041bec0 = 0x8041bec0;
SECTIONS {
  .text.w3d_construct_categories_8027b528 0x8027b528 : { *(.text.w3d_construct_categories_8027b528) }
  .sdata 0x804abbac (NOLOAD) : {
    . = 0x0; instance_804abbac = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
