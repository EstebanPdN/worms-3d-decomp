/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cx16b_shared_rebind_801a1d90)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801a2754 = 0x801a2754;
lbl_80365094 = 0x80365094;
SECTIONS {
  .text.w3d_cx16b_shared_rebind_801a1d90 0x801a1d90 : { *(.text.w3d_cx16b_shared_rebind_801a1d90) }
  .sdata 0x804ab750 (NOLOAD) : {
    . = 0x0; lbl_804ab750 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
