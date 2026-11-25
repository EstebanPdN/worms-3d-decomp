/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s19_ai_query_step_8000a6ec)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
FUN_8001aaf8 = 0x8001aaf8;
w3d_ai_capture_query_8000a68c = 0x8000a68c;
w3d_ai_set_query_origin_8000a62c = 0x8000a62c;
SECTIONS {
  .text.s19_ai_query_step_8000a6ec 0x8000a6ec : { *(.text.s19_ai_query_step_8000a6ec) }
  .rodata 0x80369bcc : { *(.rodata) }
  .sdata 0x804aa570 (NOLOAD) : {
    . = 0x0; lbl_804aa570 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
