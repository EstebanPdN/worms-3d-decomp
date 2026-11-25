/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cx9b_queued_record_dispatch_80207a58)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
queue_cursor_8045ee64 = 0x8045ee64;
SECTIONS {
  .text.w3d_cx9b_queued_record_dispatch_80207a58 0x80207a58 : { *(.text.w3d_cx9b_queued_record_dispatch_80207a58) }
  .sdata 0x804b0660 (NOLOAD) : {
    . = 0x0; dispatcher_804b0660 = .;
    . = 0x4; queue_state_804b0664 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
