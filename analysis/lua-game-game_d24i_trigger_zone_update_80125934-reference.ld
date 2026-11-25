/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d24i_trigger_zone_update_80125934)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
d24i_check_a_80125c80 = 0x80125c80;
d24i_check_b_80125d0c = 0x80125d0c;
d24i_collect_80125b44 = 0x80125b44;
d24i_iterator_finish_80126524 = 0x80126524;
d24i_iterator_next_801264fc = 0x801264fc;
d24i_iterator_start_80126334 = 0x80126334;
d24i_object_8003f240 = 0x8003f240;
d24i_on_entered_80125aa0 = 0x80125aa0;
d24i_trigger_80125d98 = 0x80125d98;
SECTIONS {
  .text.d24i_trigger_zone_update_80125934 0x80125934 : { *(.text.d24i_trigger_zone_update_80125934) }
  .sdata 0x804aa95e (NOLOAD) : {
    . = 0x0; d24i_current_804aa95e = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
