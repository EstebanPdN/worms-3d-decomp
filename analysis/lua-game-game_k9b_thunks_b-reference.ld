/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(__thunk_28_run_80270c00__6K9bTC0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
run_80270c00__6K9bTC0 = 0x80270c00;
run_8029eb04__6K9bTC1 = 0x8029eb04;
SECTIONS {
  .gnu.linkonce.t.__thunk_28_run_80270c00__6K9bTC0 0x8035eabc : { *(.gnu.linkonce.t.__thunk_28_run_80270c00__6K9bTC0) }
  .gnu.linkonce.t.__thunk_28_run_8029eb04__6K9bTC1 0x8035f234 : { *(.gnu.linkonce.t.__thunk_28_run_8029eb04__6K9bTC1) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
