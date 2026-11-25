/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d25i_frontend_settings_init_8010ee14)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cached_id_8015f5a0 = 0x8015f5a0;
cast_80341584 = 0x80341584;
n_8039a284 = 0x8039a284;
n_8039a298 = 0x8039a298;
n_8039a2ac = 0x8039a2ac;
n_8039a2bc = 0x8039a2bc;
n_8039a2cc = 0x8039a2cc;
n_8039a2dc = 0x8039a2dc;
n_8039a2ec = 0x8039a2ec;
n_8039a2fc = 0x8039a2fc;
n_8039a30c = 0x8039a30c;
n_8039a318 = 0x8039a318;
n_8039a328 = 0x8039a328;
n_8039a338 = 0x8039a338;
n_8039a34c = 0x8039a34c;
n_8039a360 = 0x8039a360;
n_8039a370 = 0x8039a370;
n_8039a380 = 0x8039a380;
n_8039a390 = 0x8039a390;
n_8039a3a0 = 0x8039a3a0;
n_8039a3b8 = 0x8039a3b8;
n_8039a3c8 = 0x8039a3c8;
n_8039a3d8 = 0x8039a3d8;
n_8039a3ec = 0x8039a3ec;
n_8039a3fc = 0x8039a3fc;
read_colour_800fc370 = 0x800fc370;
read_setting_800fc1b0 = 0x800fc1b0;
subscribe_80162024 = 0x80162024;
SECTIONS {
  .text.d25i_frontend_settings_init_8010ee14 0x8010ee14 : { *(.text.d25i_frontend_settings_init_8010ee14) }
  .sdata 0x804af308 (NOLOAD) : {
    . = 0x0; cache_804af308 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
