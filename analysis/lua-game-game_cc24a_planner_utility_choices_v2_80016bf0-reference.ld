/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(cc24a_planner_utility_choices_v2_80016bf0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cc24a_allocate_8001523c = 0x8001523c;
cc24a_available_80007ccc = 0x80007ccc;
cc24a_base_80006360 = 0x80006360;
cc24a_dispatch_8040d9c8 = 0x8040d9c8;
cc24a_dispatch_8040d9f8 = 0x8040d9f8;
cc24a_dispatch_8040da28 = 0x8040da28;
cc24a_dispatch_8040da58 = 0x8040da58;
cc24a_push_80007514 = 0x80007514;
SECTIONS {
  .text.cc24a_planner_utility_choices_v2_80016bf0 0x80016bf0 : { *(.text.cc24a_planner_utility_choices_v2_80016bf0) }
  .sdata 0x804aa58c (NOLOAD) : {
    . = 0x0; cc24a_extra_804aa58c = .;
    . = 0x8; cc24a_done_804aa594 = .;
    . = 0x14; cc24a_mode_804aa5a0 = .;
    . = 0x150; cc24a_ready_804aa6dc = .;
    . = 0x154; cc24a_busy_804aa6e0 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
