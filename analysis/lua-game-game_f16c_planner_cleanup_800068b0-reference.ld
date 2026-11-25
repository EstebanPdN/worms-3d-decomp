/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(f16c_planner_cleanup_800068b0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__dl__15F16cPlannerNamePv = 0x80015264;
__dl__17F16cPlannerBufferPv = 0x80015264;
__dl__22F16cPlannerOtherBufferPv = 0x801fe1f8;
clear12_803414b4 = 0x803414b4;
clear16_80341450 = 0x80341450;
clearNames_80341518 = 0x80341518;
copy_802eee50 = 0x802eee50;
delete_80015264 = 0x80015264;
finish0_80015db8 = 0x80015db8;
finish1_80015e64 = 0x80015e64;
finish_8020c5c4 = 0x8020c5c4;
free_802134fc = 0x802134fc;
owner_8001cac4 = 0x8001cac4;
prepare_80020b20 = 0x80020b20;
release_80341588 = 0x80341588;
SECTIONS {
  .text.f16c_planner_cleanup_800068b0 0x800068b0 : { *(.text.f16c_planner_cleanup_800068b0) }
  .sdata 0x804aa558 (NOLOAD) : {
    . = 0x0; buffer_804aa558 = .;
    . = 0x4; buffer_804aa55c = .;
    . = 0x8; buffer_804aa560 = .;
    . = 0xc; buffer_804aa564 = .;
    . = 0x10; field_804aa568 = .;
    . = 0x28; field_804aa580 = .;
    . = 0x2c; field_804aa584 = .;
    . = 0x30; field_804aa588 = .;
    . = 0x34; field_804aa58c = .;
    . = 0x38; field_804aa590 = .;
    . = 0x40; field_804aa598 = .;
    . = 0x44; field_804aa59c = .;
    . = 0x48; field_804aa5a0 = .;
    . = 0x50; storage_804aa5a8 = .;
    . = 0x17c; name_804aa6d4 = .;
    . = 0x1f8; buffer_804aa750 = .;
    . = 0x1fc; buffer_804aa754 = .;
    . = 0x200; field_804aa758 = .;
    . = 0x204; buffer_804aa75c = .;
    . = 0x7200; owner_804b1758 = .;
    . = 0x7208; owner_804b1760 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
