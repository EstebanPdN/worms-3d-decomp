/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_k6b_script_host_run_file_8019ddf4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8019dd80 = 0x8019dd80;
fn_8020b884 = 0x8020b884;
lua_call = 0x802ce6e4;
lua_load = 0x802ce7c0;
SECTIONS {
  .text.w3d_k6b_script_host_run_file_8019ddf4 0x8019ddf4 : { *(.text.w3d_k6b_script_host_run_file_8019ddf4) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
