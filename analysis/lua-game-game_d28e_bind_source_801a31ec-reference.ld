/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d28e_bind_source_801a31ec)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
alloc_80212fd4 = 0x80212fd4;
fn_801a2d68 = 0x801a2d68;
free_802134fc = 0x802134fc;
memcpy_802eee50 = 0x802eee50;
memmove_802eeef4 = 0x802eeef4;
SECTIONS {
  .text.w3d_d28e_bind_source_801a31ec 0x801a31ec : { *(.text.w3d_d28e_bind_source_801a31ec) }
  .sdata 0x804ab74c (NOLOAD) : {
    . = 0x0; lbl_804ab74c = .;
    . = 0x618c; lbl_804b18d8 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
