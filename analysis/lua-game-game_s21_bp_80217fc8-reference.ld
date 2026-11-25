/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s21_trace_80217fc8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_802fb7ac = 0x802fb7ac;
lbl_803b383c = 0x803b383c;
SECTIONS {
  .text.w3d_s21_trace_80217fc8 0x80217fc8 : { *(.text.w3d_s21_trace_80217fc8) }
  .sdata 0x804ab9a4 (NOLOAD) : {
    . = 0x0; lbl_804ab9a4 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
