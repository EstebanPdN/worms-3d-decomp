/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(cc24a_planner_category_score_8001752c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cc24a_count_800155ac = 0x800155ac;
cc24a_falloff_80017380 = 0x80017380;
cc24a_owner_query_80015540 = 0x80015540;
SECTIONS {
  .text.cc24a_planner_category_score_8001752c 0x8001752c : { *(.text.cc24a_planner_category_score_8001752c) }
  .rodata 0x8036a760 : { *(.rodata) }
  .sdata 0x804aa6c0 (NOLOAD) : {
    . = 0x0; cc24a_owner_804aa6c0 = .;
    . = 0x18; cc24a_config_804aa6d8 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
