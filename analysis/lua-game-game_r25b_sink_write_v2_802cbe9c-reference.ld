/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_r25b_sink_write_v2_802cbe9c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__8R25bTextPCc = 0x8020bb54;
append__8R25bTextPCc = 0x8020bf2c;
r25b_finish_8020c5c4__FP8R25bText = 0x8020c5c4;
r25b_release_80341588__FP8R25bText = 0x80341588;
r25b_sinks_80473724 = 0x80473724;
r25b_suffix_803d9448 = 0x803d9448;
r25b_write_802cc01c__FP8R25bSinkPCci = 0x802cc01c;
SECTIONS {
  .text.w3d_r25b_sink_write_v2_802cbe9c 0x802cbe9c : { *(.text.w3d_r25b_sink_write_v2_802cbe9c) }
  .sdata 0x804abce4 (NOLOAD) : {
    . = 0x0; r25b_enabled_804abce4 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
