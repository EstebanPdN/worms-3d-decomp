/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d30e_rle_fread_801d9fb0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
lbl_803af908 = 0x803af908;
lbl_803af930 = 0x803af930;
lbl_803af964 = 0x803af964;
lbl_803af998 = 0x803af998;
lbl_803af9b0 = 0x803af9b0;
lbl_803af9b4 = 0x803af9b4;
lbl_803af9b8 = 0x803af9b8;
memcpy = 0x802eee50;
memset = 0x802eefe0;
printf = 0x802ebfbc;
w3d_handle_storage_allocate = 0x80212fd4;
SECTIONS {
  .text.w3d_d30e_rle_fread_801d9fb0 0x801d9fb0 : { *(.text.w3d_d30e_rle_fread_801d9fb0) }
  .sdata 0x804ab7fc (NOLOAD) : {
    . = 0x0; lbl_804ab7fc = .;
    . = 0x4; lbl_804ab800 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
