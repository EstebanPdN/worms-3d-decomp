/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_buffer_manager_initialize)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_buffer_request_state = 0x8020f3b0;
w3d_buffer_shared_cell = 0x80343810;
w3d_buffer_storage_release = 0x8019821c;
w3d_temporary_owner_allocate = 0x80198248;
w3d_temporary_owner_release = 0x80198280;
SECTIONS {
  .text.w3d_buffer_manager_initialize 0x80197d78 : { *(.text.w3d_buffer_manager_initialize) }
  .text.w3d_buffer_manager_release_temporary 0x80197ed0 : { *(.text.w3d_buffer_manager_release_temporary) }
  .text.w3d_buffer_manager_move 0x80197f0c : { *(.text.w3d_buffer_manager_move) }
  .text.w3d_buffer_manager_clear_records 0x80197f98 : { *(.text.w3d_buffer_manager_clear_records) }
  .text.w3d_buffer_manager_release_storage 0x8019800c : { *(.text.w3d_buffer_manager_release_storage) }
  .text.w3d_buffer_manager_poll_state 0x80198160 : { *(.text.w3d_buffer_manager_poll_state) }
  .sdata 0x804ab6f4 (NOLOAD) : {
    . = 0x0; w3d_buffer_external_word = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
