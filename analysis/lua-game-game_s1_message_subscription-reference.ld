/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_fn_8005ff48)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_cached_message_id = 0x8015f5a0;
w3d_engine_get_context = 0x80165254;
w3d_fn_800c53a0 = 0x800c53a0;
w3d_fn_8015f704 = 0x8015f704;
w3d_fn_801613f0 = 0x801613f0;
w3d_fn_80162024 = 0x80162024;
w3d_string_assign = 0x8020bd38;
w3d_string_default = 0x803426b8;
w3d_vtable_8040db38 = 0x8040db38;
SECTIONS {
  .text.w3d_fn_8005ff48 0x8005ff48 : { *(.text.w3d_fn_8005ff48) }
  .text.w3d_fn_8005ffc8 0x8005ffc8 : { *(.text.w3d_fn_8005ffc8) }
  .sdata 0x804b1754 (NOLOAD) : {
    . = 0x0; w3d_queue_804b1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
