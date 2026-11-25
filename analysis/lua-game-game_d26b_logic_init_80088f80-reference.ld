/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d26b_logic_init_80088f80)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_acquire_message_80162024 = 0x80162024;
w3d_after_8008c954 = 0x8008c954;
w3d_after_8008cf40 = 0x8008cf40;
w3d_cached_message_8015f5a0 = 0x8015f5a0;
w3d_cast_803426b4 = 0x803426b4;
w3d_cast_80342a78 = 0x80342a78;
w3d_load_800fc1b0 = 0x800fc1b0;
w3d_text_8037d788 = 0x8037d788;
SECTIONS {
  .text.w3d_d26b_logic_init_80088f80 0x80088f80 : { *(.text.w3d_d26b_logic_init_80088f80) }
  .rodata 0x8037d7a4 : { *(.rodata) }
  .sdata 0x804adba4 (NOLOAD) : {
    . = 0x0; w3d_cache_804adba4 = .;
    . = 0x8; w3d_cache_804adbac = .;
    . = 0x10; w3d_cache_804adbb4 = .;
    . = 0x18; w3d_cache_804adbbc = .;
    . = 0x20; w3d_cache_804adbc4 = .;
    . = 0x28; w3d_cache_804adbcc = .;
    . = 0x30; w3d_cache_804adbd4 = .;
    . = 0x40; w3d_cache_804adbe4 = .;
    . = 0x48; w3d_cache_804adbec = .;
    . = 0x50; w3d_cache_804adbf4 = .;
    . = 0x58; w3d_cache_804adbfc = .;
    . = 0x60; w3d_cache_804adc04 = .;
    . = 0x68; w3d_cache_804adc0c = .;
    . = 0x70; w3d_cache_804adc14 = .;
    . = 0x78; w3d_cache_804adc1c = .;
    . = 0x80; w3d_cache_804adc24 = .;
    . = 0x88; w3d_cache_804adc2c = .;
    . = 0x90; w3d_cache_804adc34 = .;
    . = 0x98; w3d_cache_804adc3c = .;
    . = 0xa0; w3d_cache_804adc44 = .;
    . = 0xa8; w3d_cache_804adc4c = .;
    . = 0xb0; w3d_cache_804adc54 = .;
    . = 0xb8; w3d_cache_804adc5c = .;
    . = 0xc0; w3d_cache_804adc64 = .;
    . = 0xc8; w3d_cache_804adc6c = .;
    . = 0xd0; w3d_cache_804adc74 = .;
    . = 0xd8; w3d_cache_804adc7c = .;
    . = 0xe0; w3d_cache_804adc84 = .;
    . = 0xe8; w3d_cache_804adc8c = .;
    . = 0xf0; w3d_cache_804adc94 = .;
    . = 0xf8; w3d_cache_804adc9c = .;
    . = 0x100; w3d_cache_804adca4 = .;
    . = 0x108; w3d_cache_804adcac = .;
    . = 0x110; w3d_cache_804adcb4 = .;
    . = 0x118; w3d_cache_804adcbc = .;
    . = 0x120; w3d_cache_804adcc4 = .;
    . = 0x128; w3d_cache_804adccc = .;
    . = 0x140; w3d_cache_804adce4 = .;
    . = 0x158; w3d_cache_804adcfc = .;
    . = 0x160; w3d_cache_804add04 = .;
    . = 0x168; w3d_cache_804add0c = .;
    . = 0x170; w3d_cache_804add14 = .;
    . = 0x180; w3d_cache_804add24 = .;
    . = 0x188; w3d_cache_804add2c = .;
    . = 0x190; w3d_cache_804add34 = .;
    . = 0x198; w3d_cache_804add3c = .;
    . = 0x1a0; w3d_cache_804add44 = .;
    . = 0x1a8; w3d_cache_804add4c = .;
    . = 0x1b0; w3d_cache_804add54 = .;
    . = 0x1b8; w3d_cache_804add5c = .;
    . = 0x1d8; w3d_cache_804add7c = .;
    . = 0x1e0; w3d_cache_804add84 = .;
    . = 0x1f0; w3d_cache_804add94 = .;
    . = 0x200; w3d_cache_804adda4 = .;
    . = 0x208; w3d_cache_804addac = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
