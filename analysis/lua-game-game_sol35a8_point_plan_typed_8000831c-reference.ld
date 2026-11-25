/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(sol35a8_point_plan_8000831c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
sol35a8_allocate_8001523c = 0x8001523c;
sol35a8_allocate_80212fd4 = 0x80212fd4;
sol35a8_copy_802eee50 = 0x802eee50;
sol35a8_register_8002274c = 0x8002274c;
sol35a8_release_802134fc = 0x802134fc;
sol35a8_table_8040dc68 = 0x8040dc68;
SECTIONS {
  .text.sol35a8_point_plan_8000831c 0x8000831c : { *(.text.sol35a8_point_plan_8000831c) }
  .sdata 0x804aa564 (NOLOAD) : {
    . = 0x0; sol35a8_plans_804aa564 = .;
    . = 0x40; sol35a8_registry_804aa5a4 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
