/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d30c_input_process_string_800f9db8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__vt_15D24fTimedRecord = 0x80410500;
__vt_15D24fTimedString = 0x804104e0;
array_80240bf8 = 0x80240bf8;
array_80240cc8 = 0x80240cc8;
array_80240d98 = 0x80240d98;
can_accept_800f899c = 0x800f899c;
forward_8020b680 = 0x8020b680;
key_8041aa78 = 0x8041aa78;
w3d_handle_storage_allocate = 0x80212fd4;
w3d_handle_storage_fallback = 0x803413d8;
w3d_handle_storage_release = 0x802134fc;
w3d_string_base_finish = 0x8020c5c4;
w3d_string_base_init = 0x8020c5c0;
w3d_string_header = 0x80341884;
w3d_string_release = 0x80341588;
w3d_string_release_header = 0x8020bb2c;
SECTIONS {
  .text.d30c_input_process_string_800f9db8 0x800f9db8 : { *(.text.d30c_input_process_string_800f9db8) }
  .sdata 0x804abac0 (NOLOAD) : {
    . = 0x0; sink_804abac0 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
