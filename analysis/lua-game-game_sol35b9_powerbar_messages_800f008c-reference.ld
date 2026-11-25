/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(sol35b9_powerbar_messages_800f008c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
sol35b9_power_base_8015fb34 = 0x8015fb34;
sol35b9_power_config_800fc6dc = 0x800fc6dc;
sol35b9_power_equal_8015f620 = 0x8015f620;
sol35b9_power_index_80178c48 = 0x80178c48;
sol35b9_power_mode_801190d0 = 0x801190d0;
sol35b9_power_setup_800f03a0 = 0x800f03a0;
sol35b9_power_toggle_800f0984 = 0x800f0984;
sol35b9_power_value_80178d1c = 0x80178d1c;
SECTIONS {
  .text.sol35b9_powerbar_messages_800f008c 0x800f008c : { *(.text.sol35b9_powerbar_messages_800f008c) }
  .sdata 0x804af028 (NOLOAD) : {
    . = 0x0; sol35b9_power_cache_804af028 = .;
    . = 0x8; sol35b9_power_cache_804af030 = .;
    . = 0x10; sol35b9_power_cache_804af038 = .;
    . = 0x18; sol35b9_power_cache_804af040 = .;
    . = 0x20; sol35b9_power_cache_804af048 = .;
    . = 0x28; sol35b9_power_cache_804af050 = .;
    . = 0x30; sol35b9_power_cache_804af058 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
