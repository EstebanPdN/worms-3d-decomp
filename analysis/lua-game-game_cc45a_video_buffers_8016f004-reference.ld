/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(cc45a_video_buffers_8016f004)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
cc45a_allocate_801fe2a8 = 0x801fe2a8;
cc45a_configure_80303e2c = 0x80303e2c;
cc45a_copy_gamma_80309240 = 0x80309240;
cc45a_flush_803049e8 = 0x803049e8;
cc45a_release_801fe2e0 = 0x801fe2e0;
cc45a_retrace_80303964 = 0x80303964;
cc45a_set_framebuffer_80304b18 = 0x80304b18;
SECTIONS {
  .text.cc45a_video_buffers_8016f004 0x8016f004 : { *(.text.cc45a_video_buffers_8016f004) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
