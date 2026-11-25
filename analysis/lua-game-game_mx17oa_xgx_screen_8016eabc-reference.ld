/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(__15Mx17oaXGXScreen)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__16Mx17oaScreenList = 0x802109dc;
__18Mx17oaScreenRender = 0x8016f93c;
_vt.15Mx17oaXGXScreen = 0x80411e60;
_vt.16Mx17oaScreenRoot = 0x80411ea0;
set_filter_scale__15Mx17oaXGXScreenf = 0x8016ee4c;
setup_video_buffers__15Mx17oaXGXScreen = 0x8016f004;
w3d_adjust_for_overscan_80308c84 = 0x80308c84;
w3d_panic_802fb82c = 0x802fb82c;
w3d_render_mode_803fe370 = 0x803fe370;
w3d_render_mode_80408120 = 0x80408120;
w3d_render_mode_80408378 = 0x80408378;
w3d_video_init_803034b4 = 0x803034b4;
w3d_video_tv_format_80304de0 = 0x80304de0;
SECTIONS {
  .text.__15Mx17oaXGXScreen 0x8016eabc : { *(.text.__15Mx17oaXGXScreen) }
  .rodata 0x803a6420 : { *(.rodata) }
  .sdata 0x804b1888 (NOLOAD) : {
    . = 0x0; w3d_screen_804b1888 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
