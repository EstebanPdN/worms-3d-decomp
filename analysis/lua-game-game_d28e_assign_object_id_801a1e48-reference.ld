/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d28e_assign_object_id_801a1e48)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
alloc_80212fd4 = 0x80212fd4;
fn_801a2754 = 0x801a2754;
free_802134fc = 0x802134fc;
lbl_803649b4 = 0x803649b4;
lbl_804143e0 = 0x804143e0;
lbl_8045ce40 = 0x8045ce40;
lbl_8045e080 = 0x8045e080;
memcpy_802eee50 = 0x802eee50;
memmove_802eeef4 = 0x802eeef4;
r23c_max_byte_80352828 = 0x80352828;
w3d_auto_801ffea8 = 0x801ffea8;
w3d_auto_8020b648 = 0x8020b648;
SECTIONS {
  .text.w3d_d28e_assign_object_id_801a1e48 0x801a1e48 : { *(.text.w3d_d28e_assign_object_id_801a1e48) }
  .sdata 0x804ab750 (NOLOAD) : {
    . = 0x0; lbl_804ab750 = .;
    . = 0x6188; lbl_804b18d8 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
