/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d29j_compile_shader_8016b86c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_80166fd0 = 0x80166fd0;
fn_8016797c = 0x8016797c;
fn_8016aec0 = 0x8016aec0;
fn_8016aef0 = 0x8016aef0;
fn_8016afc8 = 0x8016afc8;
fn_8016b040 = 0x8016b040;
fn_8016b384 = 0x8016b384;
fn_8016b5a0 = 0x8016b5a0;
SECTIONS {
  .text.d29j_compile_shader_8016b86c 0x8016b86c : { *(.text.d29j_compile_shader_8016b86c) }
  .sdata 0x804b1884 (NOLOAD) : {
    . = 0x0; global_804b1884 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
