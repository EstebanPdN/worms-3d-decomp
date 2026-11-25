/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(codex_update_801e50c8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
terra_only_c_fn_801e4fcc = 0x801e4fcc;
terra_only_c_fn_801e50b8 = 0x801e50b8;
terra_only_c_fn_801e51c8 = 0x801e51c8;
terra_only_c_fn_801e5314 = 0x801e5314;
terra_only_c_fn_801e5460 = 0x801e5460;
terra_only_c_fn_801e560c = 0x801e560c;
terra_only_c_fn_801e5908 = 0x801e5908;
terra_only_c_fn_801e5960 = 0x801e5960;
SECTIONS {
  .text.codex_update_801e50c8 0x801e50c8 : { *(.text.codex_update_801e50c8) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
