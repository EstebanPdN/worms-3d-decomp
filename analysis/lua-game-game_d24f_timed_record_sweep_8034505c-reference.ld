/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d24f_timed_record_sweep_8034505c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
_S_oom_malloc__Q24_STLt14__malloc_alloc1i0Ui = 0x803413d8;
__vt_13D24fTimedWord = 0x804104f0;
__vt_15D24fTimedRecord = 0x80410500;
free = 0x802134fc;
malloc = 0x80212fd4;
w3d_message_post_current = 0x8016239c;
SECTIONS {
  .text.d24f_timed_record_sweep_8034505c 0x8034505c : { *(.text.d24f_timed_record_sweep_8034505c) }
  .sdata 0x804b1788 (NOLOAD) : {
    . = 0x0; lbl_804b1788 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
