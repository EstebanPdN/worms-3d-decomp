/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(sol35b2_update_800e8934)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
sol35b2_accumulate_800e9528 = 0x800e9528;
sol35b2_config_801797b4 = 0x801797b4;
sol35b2_display_800e92fc = 0x800e92fc;
sol35b2_forward_800e95e0 = 0x800e95e0;
sol35b2_forward_800e962c = 0x800e962c;
sol35b2_notify_800e8a88 = 0x800e8a88;
sol35b2_paused_8006e71c = 0x8006e71c;
sol35b2_sync_80341584 = 0x80341584;
sol35b2_trail_800e9d08 = 0x800e9d08;
SECTIONS {
  .text.sol35b2_update_800e8934 0x800e8934 : { *(.text.sol35b2_update_800e8934) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
