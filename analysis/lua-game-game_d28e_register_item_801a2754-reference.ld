/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d28e_register_item_801a2754)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
alloc_80212fd4 = 0x80212fd4;
fn_801a2d68 = 0x801a2d68;
free_802134fc = 0x802134fc;
lbl_80365094 = 0x80365094;
memcpy_802eee50 = 0x802eee50;
memmove_802eeef4 = 0x802eeef4;
SECTIONS {
  .text.w3d_d28e_register_item_801a2754 0x801a2754 : { *(.text.w3d_d28e_register_item_801a2754) }
  .sdata 0x804b18d8 (NOLOAD) : {
    . = 0x0; lbl_804b18d8 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
