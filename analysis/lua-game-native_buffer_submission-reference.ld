/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_buffer_manager_register)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_buffer_request_service = 0x80343944;
w3d_buffer_request_write = 0x8020f4b0;
w3d_buffer_shared_cell = 0x80343810;
w3d_temporary_owner_release = 0x80198280;
SECTIONS {
  .text.w3d_buffer_manager_register 0x80197dd4 : { *(.text.w3d_buffer_manager_register) }
  .text.w3d_buffer_manager_submit 0x80197e08 : { *(.text.w3d_buffer_manager_submit) }
  .sdata 0x804ab6f4 (NOLOAD) : {
    . = 0x0; w3d_buffer_external_word = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
