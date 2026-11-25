/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s4_save_history_remove)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_history_leave_8028e8ec = 0x8028e8ec;
w3d_history_queue_push_8035f0cc = 0x8035f0cc;
w3d_name_remove_800c47f8 = 0x800c47f8;
SECTIONS {
  .text.w3d_s4_save_history_remove 0x8028eb54 : { *(.text.w3d_s4_save_history_remove) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
