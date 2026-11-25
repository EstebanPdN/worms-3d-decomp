/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d33e_read_object_header_80202f34)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
lbl_803b2b54 = 0x803b2b54;
lbl_803b2b60 = 0x803b2b60;
memset = 0x802eefe0;
w3d_s21_read_forward_802025a8 = 0x802025a8;
w3d_trace_stub_80347324 = 0x80347324;
SECTIONS {
  .text.w3d_d33e_read_object_header_80202f34 0x80202f34 : { *(.text.w3d_d33e_read_object_header_80202f34) }
  .sdata 0x804b0640 (NOLOAD) : {
    . = 0x0; g_trace = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
