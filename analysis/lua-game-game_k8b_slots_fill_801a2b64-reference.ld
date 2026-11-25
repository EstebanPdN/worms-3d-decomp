/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_k8b_slots_fill_801a2b64)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
SECTIONS {
  .text.w3d_k8b_slots_fill_801a2b64 0x801a2b64 : { *(.text.w3d_k8b_slots_fill_801a2b64) }
  .sdata 0x804ab74c (NOLOAD) : {
    . = 0x0; lbl_804ab74c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
