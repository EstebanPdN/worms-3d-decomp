/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(cc28a_planner_reset_dispatch_80021234)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cc28a_clear_80022664 = 0x80022664;
cc28a_default_8036bba8 = 0x8036bba8;
cc28a_destroy_80021468 = 0x80021468;
cc28a_reset_80006694 = 0x80006694;
cc28a_table_8040dbe8 = 0x8040dbe8;
SECTIONS {
  .text.cc28a_planner_reset_dispatch_80021234 0x80021234 : { *(.text.cc28a_planner_reset_dispatch_80021234) }
  .sdata 0x804aa568 (NOLOAD) : {
    . = 0x0; cc28a_state_804aa568 = .;
    . = 0x360; cc28a_service_804aa8c8 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
