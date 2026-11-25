/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d24h_pool_expire_800c5164)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8016239c = 0x8016239c;
lbl_803f5718 = 0x803f5718;
lbl_8043e438 = 0x8043e438;
lbl_8043e448 = 0x8043e448;
lbl_804a85d8 = 0x804a85d8;
memmove = 0x802eeef4;
w3d_auto_800f74d0 = 0x800f74d0;
w3d_get_800f7508 = 0x800f7508;
w3d_get_800f7518 = 0x800f7518;
w3d_get_800f7528 = 0x800f7528;
w3d_handle_storage_allocate = 0x80212fd4;
w3d_handle_storage_fallback = 0x803413d8;
w3d_handle_storage_release = 0x802134fc;
w3d_heap_release = 0x80209920;
SECTIONS {
  .text.w3d_d24h_pool_expire_800c5164 0x800c5164 : { *(.text.w3d_d24h_pool_expire_800c5164) }
  .sdata 0x804af100 (NOLOAD) : {
    . = 0x0; lbl_804af100 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
