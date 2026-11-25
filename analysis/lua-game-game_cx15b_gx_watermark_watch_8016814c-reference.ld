/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cx15b_gx_watermark_watch_8016814c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
abort_801683c4 = 0x801683c4;
file_803a4e58 = 0x803a4e58;
message_803a4e6c = 0x803a4e6c;
panic_802fb82c = 0x802fb82c;
progress_80306cc8 = 0x80306cc8;
report_802fb7ac = 0x802fb7ac;
status_803069fc = 0x803069fc;
warning_803a4e20 = 0x803a4e20;
SECTIONS {
  .text.w3d_cx15b_gx_watermark_watch_8016814c 0x8016814c : { *(.text.w3d_cx15b_gx_watermark_watch_8016814c) }
  .sdata 0x804ab504 (NOLOAD) : {
    . = 0x0; hangs_804ab504 = .;
    . = 0x4; last_804ab508 = .;
    . = 0x4be0; ticks_804b00e4 = .;
    . = 0x4be4; limit_804b00e8 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
