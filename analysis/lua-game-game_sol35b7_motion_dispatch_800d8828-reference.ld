/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(sol35b7_motion_dispatch_800d8828)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
sol35b7_config_801797b4 = 0x801797b4;
sol35b7_prepare_800ec5c8 = 0x800ec5c8;
sol35b7_refresh_800ecb20 = 0x800ecb20;
sol35b7_schedule_800d973c = 0x800d973c;
sol35b7_start_800d8b4c = 0x800d8b4c;
sol35b7_stop_800d8938 = 0x800d8938;
sol35b7_sync_80341584 = 0x80341584;
sol35b7_threshold_8038928c = 0x8038928c;
SECTIONS {
  .text.sol35b7_motion_dispatch_800d8828 0x800d8828 : { *(.text.sol35b7_motion_dispatch_800d8828) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
