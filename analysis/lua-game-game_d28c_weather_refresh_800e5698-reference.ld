/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d28c_weather_refresh_800e5698)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
arena_alloc_801613f0 = 0x801613f0;
cached_8015f5a0 = 0x8015f5a0;
context_80165254 = 0x80165254;
format_803434d4 = 0x803434d4;
physics_800e58fc = 0x800e58fc;
pool_add_800c53a0 = 0x800c53a0;
random_80162ba8 = 0x80162ba8;
setting_800fc230 = 0x800fc230;
spawn_800e5da0 = 0x800e5da0;
stop_800e5bb8 = 0x800e5bb8;
vt_8040db38 = 0x8040db38;
zero_8045e788 = 0x8045e788;
SECTIONS {
  .text.d28c_weather_refresh_800e5698 0x800e5698 : { *(.text.d28c_weather_refresh_800e5698) }
  .rodata 0x8038a4b8 : { *(.rodata) }
  .sdata 0x804aede4 (NOLOAD) : {
    . = 0x0; id_804aede4 = .;
    . = 0x2970; arena_804b1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
