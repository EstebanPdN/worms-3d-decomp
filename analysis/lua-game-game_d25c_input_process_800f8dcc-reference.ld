/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d25c_input_process_800f8dcc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__vt_15D24fTimedRecord = 0x80410500;
array_80240bf8 = 0x80240bf8;
array_80240cc8 = 0x80240cc8;
can_accept_800f899c = 0x800f899c;
forward_8020b680 = 0x8020b680;
key_8041aa68 = 0x8041aa68;
w3d_handle_storage_allocate = 0x80212fd4;
w3d_handle_storage_fallback = 0x803413d8;
w3d_handle_storage_release = 0x802134fc;
SECTIONS {
  .text.d25c_input_process_800f8dcc 0x800f8dcc : { *(.text.d25c_input_process_800f8dcc) }
  .sdata 0x804abac0 (NOLOAD) : {
    . = 0x0; sink_804abac0 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
