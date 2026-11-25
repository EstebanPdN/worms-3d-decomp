/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d28e_reset_batches_801a966c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
alloc_80212fd4 = 0x80212fd4;
free_802134fc = 0x802134fc;
lbl_80414ae0 = 0x80414ae0;
memcpy_802eee50 = 0x802eee50;
w3d_auto_80209de4 = 0x80209de4;
w3d_s10_service_forward_8020b680 = 0x8020b680;
SECTIONS {
  .text.w3d_d28e_reset_batches_801a966c 0x801a966c : { *(.text.w3d_d28e_reset_batches_801a966c) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
