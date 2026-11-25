/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d29e_run_file_8020b6e8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
_._6Tagged = 0x8020803c;
__6Tagged = 0x80207fec;
lbl_803b3104 = 0x803b3104;
lbl_803b3130 = 0x803b3130;
lbl_80418de0 = 0x80418de0;
lbl_80419848 = 0x80419848;
refill__6TaggedPvi = 0x802080a0;
w3d_s10_assign_interface_802199c0 = 0x802199c0;
w3d_s10_service_forward_8020b680 = 0x8020b680;
w3d_trace_stub_80347324 = 0x80347324;
SECTIONS {
  .text.w3d_d29e_run_file_8020b6e8 0x8020b6e8 : { *(.text.w3d_d29e_run_file_8020b6e8) }
  .sdata 0x804b0640 (NOLOAD) : {
    . = 0x0; lbl_804b0640 = .;
    . = 0x5c; lbl_804b069c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
