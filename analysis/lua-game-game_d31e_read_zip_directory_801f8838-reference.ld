/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d31e_read_zip_directory_801f8838)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
s_file = 0x803b1974;
sol35d10_read_end_record_801f8c48 = 0x801f8c48;
strncpy = 0x802efbfc;
tsonnet_c26_temp_alloc_801fe0b8 = 0x801fe0b8;
w3d_aligned_allocate_801fe2a8 = 0x801fe2a8;
w3d_auto_801f87f0 = 0x801f87f0;
w3d_auto_801f8b7c = 0x801f8b7c;
w3d_trace_stub_80347324 = 0x80347324;
SECTIONS {
  .text.w3d_d31e_read_zip_directory_801f8838 0x801f8838 : { *(.text.w3d_d31e_read_zip_directory_801f8838) }
  .sdata 0x804b0640 (NOLOAD) : {
    . = 0x0; g_trace = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
