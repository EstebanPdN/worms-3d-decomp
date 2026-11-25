/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(cc45a_swap_8016eed0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cc45a_alpha_8030ba0c = 0x8030ba0c;
cc45a_begin_8016ee48 = 0x8016ee48;
cc45a_black_80304b84 = 0x80304b84;
cc45a_copy_80309254 = 0x80309254;
cc45a_done_803085a0 = 0x803085a0;
cc45a_filter_80309038 = 0x80309038;
cc45a_flush_803049e8 = 0x803049e8;
cc45a_framebuffer_80304b18 = 0x80304b18;
cc45a_retrace_80303964 = 0x80303964;
cc45a_scale_8016ee4c = 0x8016ee4c;
SECTIONS {
  .text.cc45a_swap_8016eed0 0x8016eed0 : { *(.text.cc45a_swap_8016eed0) }
  .sdata 0x804ab55c (NOLOAD) : {
    . = 0x0; cc45a_startup_frames_804ab55c = .;
    . = 0x6328; cc45a_graphics_804b1884 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
