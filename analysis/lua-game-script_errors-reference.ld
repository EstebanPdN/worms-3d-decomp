/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_source_line_data)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
memcpy = 0x802eee50;
w3d_log_message = 0x802cbe9c;
w3d_message_find_id = 0x80161f54;
w3d_string_base_init = 0x8020c5c0;
w3d_string_header = 0x80341884;
SECTIONS {
  .text.w3d_source_line_data 0x800ffb68 : { *(.text.w3d_source_line_data) }
  .text.w3d_source_line_size 0x800ffb70 : { *(.text.w3d_source_line_size) }
  .text.w3d_source_document_name 0x800ffcdc : { *(.text.w3d_source_document_name) }
  .text.w3d_script_log 0x801022b0 : { *(.text.w3d_script_log) }
  .text.w3d_script_output_hook 0x801022e8 : { *(.text.w3d_script_output_hook) }
  .text.w3d_script_set_run_state 0x8010272c : { *(.text.w3d_script_set_run_state) }
  .text.w3d_script_source_line 0x80102890 : { *(.text.w3d_script_source_line) }
  .text.w3d_cached_message_base_init 0x8015f4c4 : { *(.text.w3d_cached_message_base_init) }
  .text.w3d_cached_message_name_init 0x8015f518 : { *(.text.w3d_cached_message_name_init) }
  .text.w3d_cached_message_id 0x8015f5a0 : { *(.text.w3d_cached_message_id) }
  .rodata 0x80398f30 : { *(.rodata) }
  .sdata 0x804aaf88 (NOLOAD) : {
    . = 0x0; w3d_script_log_channel = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
